import libcamera
import cv2
import time
import numpy as np

def display_fps(index):
    display_fps.frame_count += 1
    current = time.time()
    if current - display_fps.start >= 1:
        print("fps: {}".format(display_fps.frame_count))
        display_fps.frame_count = 0
        display_fps.start = current

display_fps.start = time.time()
display_fps.frame_count = 0

if __name__ == "__main__":
    width = 640
    height = 480
    framerate = 30

    # Instantiate the libcamera class
    cam = libcamera.libcamera()

    """
    Initialize the camera

    :param1 width: Set image width
    :param2 height: Set image height
    :param3 pixelFormat: Set image format
    :param4 buffercount: Set the number of buffers
    :param5 rotation: Set the image rotation angle
    :returns ret: Whether the camera is initialized successfully
    """
    ret = cam.initCamera(width, height, libcamera.PixelFormat.RGB888, buffercount=4, rotation=0)

    if not ret:

        # Turn on the camera
        ret = cam.startCamera()

        # Set frame rate
        frame_time = 1000000 // framerate
        cam.set(libcamera.FrameDurationLimits, [frame_time, frame_time])
        cam.set(libcamera.ExposureTime, 500)
        while True:

            """
            Read image information
            
            :returns ret: Whether the image is successfully read
            :returns data: Image data information
            """
            ret, data = cam.readFrame()

            if not ret:
                continue

            # Get image data
            # At present, only RGB888, BGR888, XRGB8888 can be displayed directly, no conversion
            frame = data.imageData

            cv2.imshow("image", frame)

            key = cv2.waitKey(1)
            if key == ord("q"):
                break
            elif key == ord("s"):
                cv2.imwrite("test.jpg", frame)

            display_fps(0)

            """
            Return image buffer

            :param data: Send image data back
            """
            cam.returnFrameBuffer(data)
        
        cam.stopCamera()

    cam.closeCamera()
