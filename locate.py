import cv2
import numpy as np
import sys
print("Test")

#Read in image and convert it to grey
image = cv2.imread(sys.argv[1])
image_grey = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

#Read in Waldo
waldo_01 = cv2.imread('waldo01.png',0)
waldo_02 = cv2.imread('waldo02.png',0)
waldo_03 = cv2.imread('waldo03.png',0)
height_w1 = waldo_01.shape[0]
width_w1 = waldo_01.shape[1]
height_w2 = waldo_02.shape[0]
width_w2 = waldo_02.shape[1]
height_w3 = waldo_03.shape[0]
width_w3 = waldo_03.shape[1]

find_w1 = cv2.matchTemplate(image_grey,waldo_01,cv2.TM_CCOEFF_NORMED)
find_w2 = cv2.matchTemplate(image_grey,waldo_02,cv2.TM_CCOEFF_NORMED)
find_w3 = cv2.matchTemplate(image_grey,waldo_03,cv2.TM_CCOEFF_NORMED)

threshold = 0.6

location_w1 = np.where(find_w1 >= threshold)
location_w2 = np.where(find_w2 >= threshold)
location_w3 = np.where(find_w3 >= threshold)
print(find_w1)
print(location_w1)

#find x - print(location[0] + (width / 2))
#find y - print(location[1] + (height / 2))
if location_w1 or location_w2 or location_w3:
    print("true")
else:
    print("false")