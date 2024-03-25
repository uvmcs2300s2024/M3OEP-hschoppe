# M3OEP-hschoppe - Hailey Schoppe

### Instructions for Running Program

To run the program, simply visit the website https://hschoppe.w3.uvm.edu/M3OEP-hschoppe/waldo.html and upload an image. While you CAN search for an image file that has Waldo, the likelihood of it correctly registering Waldo is quite low, so I have provided one that is proven to work (WHERESWALDO.jpg) so that while testing you can have at least one example of the functionality.

### Program Summary

My program takes an image and determines if it has Waldo in it. It does so by testing a handful of images of Waldo throughout the years through python cv2 to see if anything within the image seems to match. However, due to how limited the cv2 matching software is, this leads to quite a few erroneous results (particularly in the direction of not finding Waldo)

### Languages Involved

This program starts in HTML, where it allows the user to upload an image file. This is then passed into PHP, as can be seen in the waldo.html file, where the file is verified, information on it is gathered, and then it is passed into a Python file (as seen in line 88). This Python file determines whether waldo is present using the cv2 library, and then prints it out once again in HTML. The HTML throughout is paired with CSS code, with the colors and style choices all chosen and programmed by Professor Lisa Dion.

The HTML is a good choice for this project because, in creating a website, it provides an easily accessible place to upload images. The PHP is then used mainly as a hub to run other languages out of (Python in this case) but is also very useful for gathering information on the image. I believe this was the best language for this portion of the project because it is the only one we learned that connects easily with HTML and has the capabilities of doing what is asked of it in this program. Lastly, the Python is used to search for Waldo, because the cv2 libraries in Python are the only ones I could find that allow for image searching.

### Known Bugs

The only bug I have really come across with this is that a handful of images have trouble being read in. The program will still function as intended, except a small error message will appear above the image once it loads in explaining an error. However, this is very rare. The much more common issue is that images with Waldo will come back as not having Waldo present - this is less of an error and more a product of the limitations of cv2 image finding libraries.

### Future Work

With a little bit more time, I would have focused on my initial plan, which was creating a game where the website would tell you how far you were from Waldo every time you clicked. I also was considering adding it so that Waldo would be circled, so that it is a Waldo solver. I believe with another day I could have implemented either method, but I ran out of time.

### Credit

- https://www.w3schools.com/php/php_file_upload.asp
- https://stackoverflow.com/questions/173868/how-can-i-get-a-files-extension-in-php
- https://medium.com/analytics-vidhya/finding-waldo-feature-matching-for-opencv-9bded7f5ab10
- Large amounts of code from Lisa Dion
Credits are also administered throughout the code where they are used.

### The Grade I Think I Deserved
- Main Program Complexity: 40/40 - I think this project both hit most topics from unit three, with a heavy focus on multiple languages interacting, and was sufficiently complicated, as it dealt with image interactions and python libraries that we have not used in class (and also, thanks to python being installed twice on my computer, meaning that certain libraries would work when run through the shell manually but not through shell_exec, took upwards of 15-20 hours and the help of at least four TAs to solve)
- Use of multiple languages: 20/20 - Three main languages are used (Python, HTML, and PHP) and CSS is also used. Each of them also have an integral part within the code.
- Choice of Languages: 20/20 - I believe that each of the languages I chose were the best possible decision given what we have covered in class.
- Command line arguments: 20/20 The command line is used quite a bit to move files between directories, create, and remove directories. It is also used to pass an image file from HTML into PHP and then run a Python code, while passing the image file through, from PHP.
- Style, Video, and Lifespan: -0 I believe I did all of these aspects fairly well.

TOTAL: 90-100 considering room for error.
