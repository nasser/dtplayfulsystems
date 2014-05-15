#!/bin/bash

sudo modprobe v4l2loopback

gst-launch -v multifilesrc location=%02d.png loop=1 caps="image/png,framerate=15/1" ! pngdec ! ffmpegcolorspace ! "video/x-raw-yuv,format=(fourcc)YUY2" ! videorate ! v4l2sink device=/dev/video1

exit 0