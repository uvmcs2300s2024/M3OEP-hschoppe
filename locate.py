import cv2
import numpy as np

#Read in image and convert it to grey
image = cv2.imread(sys.argv[1])
image_grey = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

#Read in Waldo
waldo = cv2.imread('waldo.png',0)
height = waldo.shape[0]
width = waldo.shape[1]

find = cv.matchTemplate(image_grey,waldo,cv.TM_CCOEFF_NORMED)
threshold = 0.6

location = np.where(find >= threshold)

#find x - print(location[0] + (width / 2))
#find y - print(location[1] + (height / 2))
if location:
    print('true')
else:
    print('false')