import cv2 as cv
import sys

print ("Package Imported")

img = cv.imread("/opt/hamzstlib/icon/freya.png")
if img is None:
    sys.exit("Could not read the image.")
cv.imshow("My Goddess", img)
k = cv.waitKey(0)
if k == ord("s"):
    cv.imwrite("freya_night.png", img)
