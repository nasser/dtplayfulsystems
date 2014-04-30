/* frequencyModulation
   <p>
   A simple example for doing FM (frequency modulation) using two Oscils.
   <p>
   For more information about Minim and additional features, 
   visit http://code.compartmental.net/minim/
   <p>  
   Author: Damien Di Fede
 */
 
 /* spaceBrew connection by Joselyn McDonald 4/27 */

//import the Serial library so can read from arudino input via serial communication

//import processing.serial.*;
import spacebrew.*;
String server="sandbox.spacebrew.cc";
String name="Jos_frequency";
String description ="Client that sends and receives range messages. Range values go from 0 to 1023.";


Spacebrew sb;
//int local_slider_val = 512;

int remote_slider_val = 50;


//int end = 10;    // the number 10 is ASCII for linefeed (end of serial.println), later we will look for this to break up individual messages
//String serial;   // declare a new string called 'serial' 
//Serial port;  // The serial port, this is a new instance of the Serial class (an Object)
 
 
// import everything necessary to make sound.
import ddf.minim.*;
import ddf.minim.ugens.*;
 

// create all of the variables that will need to be accessed in
// more than one methods (setup(), draw(), stop()).
Minim minim;
AudioOutput out;

// the Oscil we use for modulating frequency.
Oscil fm;

void setup()
{
  
  // initialize the drawing window
  size( 512, 200, P3D );

  // initialize the minim and out objects
  minim = new Minim( this );
  out   = minim.getLineOut();
  
 // instantiate the spacebrewConnection variable

   sb = new Spacebrew( this );

  // Spacebrew: declare your subscribers
  sb.addSubscribe( "remote_slider", "range"); 
  
    // connect!
  sb.connect(server, name, description); 
  
  // make the Oscil we will hear.
  // arguments are frequency, amplitude, and waveform
  Oscil wave = new Oscil( 200, 0.8, Waves.TRIANGLE );
  // make the Oscil we will use to modulate the frequency of wave.
  // the frequency of this Oscil will determine how quickly the
  // frequency of wave changes and the amplitude determines how much.
  // since we are using the output of fm directly to set the frequency 
  // of wave, you can think of the amplitude as being expressed in Hz.
  fm   = new Oscil( 10, 2, Waves.SINE );
  // set the offset of fm so that it generates values centered around 200 Hz
  fm.offset.setLastValue( 200 );
  // patch it to the frequency of wave so it controls it
  fm.patch( wave.frequency );
  // and patch wave to the output
  wave.patch( out );
}

// draw is run many times
void draw()
{
  // erase the window to black
  background( 0 );
  // draw using a white stroke
  stroke( 255 );
  // draw the waveforms
  for( int i = 0; i < out.bufferSize() - 1; i++ )
  {
    // find the x position of each buffer value
    float x1  =  map( i, 0, out.bufferSize(), 0, width );
    float x2  =  map( i+1, 0, out.bufferSize(), 0, width );
    // draw a line from one buffer position to the next for both channels
    line( x1, 50 + out.left.get(i)*50, x2, 50 + out.left.get(i+1)*50);
    line( x1, 150 + out.right.get(i)*50, x2, 150 + out.right.get(i+1)*50);
  }  
  
  text( "Modulation frequency: " + fm.frequency.getLastValue(), 5, 15 );
  text( "Modulation amplitude: " + fm.amplitude.getLastValue(), 5, 30 );
  
  float modulateAmount = remote_slider_val/2;   

  float modulateFrequency = remote_slider_val/3; 
  
  fm.setFrequency( modulateFrequency );
  fm.setAmplitude( modulateAmount );
}


//void mouseMoved()
//{
//  float modulateAmount = map( mouseY, 0, height, 330, 1 );
//  float modulateFrequency = map( mouseX, 0, width, .1, 100 );
//  
//  fm.setFrequency( modulateFrequency );
//  fm.setAmplitude( modulateAmount );
//}

void onRangeMessage( String name, int value ){
  println("got range message " + name + " : " + value);
  remote_slider_val = value;
}
