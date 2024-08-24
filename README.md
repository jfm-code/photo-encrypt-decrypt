# Photo Basic Encryption Decryption

## Description
This project is to encrypt the image, turn the given image into a complete different image (encrypt it). And if we use the program and put the encrypted image as the input file, then we'll get the output image decrypted (we'll get the original image). 

## Features
- In order to encrypt the image, I grab the original image's pixels and do some XOR operations with a number that I got from the generate() function. I do this for every pixel in the original image, then I update the pixel of the image.
- My tests are used to test the step(), generate(), and overload operator<< functions. The test case "testStep" is used to check if the bits are shifted and the XOR are implemented correctly. Next, my two tests called "testGenerate1" and "testGenerate2" used boundary values such as 15 and 16 bits to see if the program crashes or has off-by-one mistake or not. I believe that boundary testing is necessary for any test cases. Lastly, I test my overload function using the "testOstream" to check if the object is printed correctly or not, or it is reversed. After writing the transform() function, I have one more test called "testEncrypt" that check if the edited image is the same as the expected one.
