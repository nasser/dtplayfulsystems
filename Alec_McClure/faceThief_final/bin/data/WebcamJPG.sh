#!/bin/bash

sudo modprobe v4l2loopback

gst-launch -v multifilesrc location=data/%02d.jpg loop=1 caps="image/jpeg,framerate=15/1" ! jpegdec ! ffmpegcolorspace ! "video/x-raw-yuv,format=(fourcc)YUY2" ! videorate ! v4l2sink device=/dev/video1

exit 0