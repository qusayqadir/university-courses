#!/usr/bin/env python
# coding: utf-8

# # Computing 5 Assignment
# 
# 

# ---
# ## Background
# 
# In this assignment you will be implementing a set of functions used in conjunction to form a website login system. Your system will utilize a text file for storing, retrieving, and verifying user credentials. We identify users based on their **username** and **password**. For simplicity we assume that usernames and passwords only contain alphanumeric characters. Alphanumeric characters represent the numbers **0-9** and the letters **A-Z** (both uppercase and lowercase). Usernames and passwords are case sensitive and must contain **at least 6** characters. Usernames must be unique.
# 
# Each username and password combination will be stored on its own line in the text file. Each line in the text file has the following format:
# 
# 
# <br>
# \begin{align}
#   \texttt{username\tpassword\n}\tag{1}
# \end{align}
# <br>
# 
# More explicitly, each line in the text file will contain a user’s username, a tab character, and that user’s password followed by the newline character. Please note that when opening the text file for viewing you will not explicitly see the **\t** and **\n** characters.
# 
# 
# In your implementation, usernames and passwords will be stored as plain text. This means that all usernames and passwords can easily be compromised if access to the text file is provided. This is extremely dangerous in the real world and poses huge security issues. In practicality, passwords are encrypted before stored so that they are not easily identifiable in the event of a data breach. Thus, please do not use any real passwords when developing and testing your program. 
# 

# ---
# ## Program Requirements (12 Marks)
# 
# Your task is to implement a set of functions that will be used in conjunction to form a website login system. Your system will read and write user credentials from a text file that emulates a database. The requirements of the system are given below. 
# Please ensure that your functions have the EXACT naming as specified! Failure to do so will result in lost marks. You can choose to copy and paste the function names into the implementation cell to avoid spelling mistakes.
# 
# 
# 1. Define a function **get_user_data**(*filename*):
#   - ***filename***: A *string* representing the name of the text file (ex. “database.txt”) that stores user login credentials in the form of ```username\tpassword\n```.
#   - **Function Description**: The function performs the following actions as defined by the pseudocode below:
#     - Opens a file with the name *filename* for reading.
#     - Initializes two empty lists: **usernames**, and **passwords**
#     - For each line in file:
#         - Strips the line of the newline character "\n" using strip() and then splits it at the tab "\t" character using split(). 
#         - Extracts the username and password in each line. 
#         - The username is appended as a string to **usernames** and the password is appended as a string to **passwords**. 
#     - Closes the file with the name *filename*<br>*(Note that it is assumed that the file associated with filename exists before the function is called)*    
#   - **Return**: A *list of lists* of length 2 where the first list is the **usernames** list and the second list is the **passwords** list populated with the data from *filename* as described above. <br>
# 
# 
# 2. Define a function **exists**(*username*, *username_list*):
#   - ***username***: A *string* representing a username.
#   - ***username_list***: A *list* containing all usernames from *filename*.
#   - **Return**: *True* if *username* exists in *username_list*, otherwise *False*.<br>*(Hint: Use the **in** keyword.)*
# 
# 
# 3. Define a function **create_user**(*username*, *password*, *username_list*, *filename*):
#   - ***username***: A *string* representing a username.
#   - ***password***: A *string* representing a password.
#   - ***username_list***: A *list* containing all usernames from *filename*.
#   - ***filename***: A *string* representing the name of the text file (ex. “database.txt”) that stores user login credentials in the form of ```username\tpassword\n```.
#   - **Function Description**: The function performs the following actions:
#     - If *username* **does not** exist in *filename*, open *filename* in append mode, write the username and password in the form ```username\tpassword\n```, and close the file.
#     - If *username* **does** exist in *filename*, do nothing.
#   - **Return**: *True* if *username* and *password* were added to *filename*, otherwise *False*<br>*(Hint: Use your **exists** function to check if the username exists in username_list and remember to close your file if you open it.)*
# 
# 
# 4. Define a function **login**(*username*, *password*, *filename*):
#   - ***username***: A *string* representing a username.
#   - ***password***: A *string* representing a password.
#   - ***filename***: A *string* representing the name of the text file
#   - **Function Description**: The function performs the following actions:
#     - If *username* **does** exist in *filename*, find the password associated with *username* in *filename* using the index of the *username* and check if *password* is equal to the expected password.<br> *(Hint: Use your **get_user_data** and **exists** functions and the **index()** method.)*
#     - If the username **does not** exist in *filename*, do nothing.
#   - **Return**: *True* if *password* matches the password associated with *username* in *filename*. *False* if the passwords do not match or *username* does not exist in *filename*.

# ---
# ## Implementation
# Please define all functions in the cell below

# In[1]:


#********************************************
# Write your get_user_data function below: (2.5 marks)
#********************************************


def get_user_data(filename):
    usernames = []      
    passwords = []      

    file_data = open(filename,"r")      #opening given file and storing in file_data
  
    
    for lines in file_data:
        lines = lines.strip()      
        lines = lines.split("\t") #spliting the string into two when it reaches '\t'
      
        usernames.append(lines[0])      #appending username where lines[0] 
        passwords.append(lines[1])      #appending password where lines[0] 
      
      
    file_data.close()       
  
    return list([usernames,passwords]) #returning 2d list of username and password
        


#********************************************
# Write your exists function below: (2.5 marks)
#********************************************


def exists(username,username_list):
    if username in username_list: #if username list contains username then return true 
        return True
    else:
        return False




    
#********************************************
# Write your create_user function below: (2.5 marks)
#********************************************
def create_user(username,password,username_list,filename):

    if exists(username, username_list):         #if username exist then do nothing
        return False
    else:  # if first condition is true then add new username and passwords in file
        userdata = open("database.txt",'a') 
        userdata.write(username+"\t"+password+"\n")##appends string to new 
        userdata.close()   #closing file
        return True
  
  
# to ceck if username password are correct



#********************************************
# Write your login function below: (4.5 marks)
#********************************************
def login(username,password,filename):
    userData = get_user_data(filename)      # get list of username and passwords

    if exists(username, userData[0]): #checks if username is in the file
        # if the password is equal to the password in the file for that specific username, return true. 
        if password == userData[1][userData[0].index(username)]:       
            ##userData[1] is the index of the list for the password is, 
            ##and the other half of the code will return the index to the username back to its userlist
            return True
    else:                           
        return False



# ---
# ## Testing
# 
# The cell below contains a main function that you can use to test your functions. 
# 
# ### Important
# Run the cell where you implemented your functions ***first*** and ensure it outputs with no errors. Then, run the cell below with the main function to verify that your code works correctly with the provided input.
# 

# In[ ]:


# TESTING
def main():

    database = "database.txt"
    filename = "database.txt"
    while True:
        ans = input("Press [q] to quit, [l] to login, [c] to create an account: ")
        if ans == "q":
            # Break if the user quits
            break
        elif ans == "l":
            # Login if the user types in "l"
            uname = input("Please enter your username: ")
            password = input("Please enter your password: ")
            if login(uname, password, database):
                print("Login sucessful!\n")
            else:
                print("Sorry, login unsucessful :(\n")
        elif ans == "c":
            # Create an account if the user types in c
            uname = input("Please create a username: ")
            password = input("Please create a password: ")
            # Check if username exists
            if create_user(uname, password, database, filename):
                    print("Account creation sucessful for user,",uname,"\n")
            else:
                    print("Sorry,",uname,"is already taken!\n")
        else:
            print("Please enter a valid character")
main()


# The main function above utilizes the functions you have created to simulate the login system environment. Inspect the code and play around with the funtionality to test out all of your functions. A file has already been created for you called "database.txt". This file contains one user with the following credentials:
# 
# Username: iLoveMac
# Password: iamthebeststudent123
# 
# Use the credentials to log into the system or create your own using the main function!

# ----------
# ## Code Legibility (6 Marks)
# Your code will be marked on commenting and code legibility.<br>
# The mark breakdown is as follows:<br>
# 
# >- 2 marks for using **appropriate variable names** that indicate what is being stored in that variable<br>
# >- 2 marks for leaving **comments on major parts of your code** such as where you read the file or calculate a summation<br>
# >- 2 marks for **general legibility**. The TA's should be able to understand your code without spending hours reading it. For example do not put your code in one very long line as this is hard for someone else reading your code to understand

# ---
# ## Reflective Questions (6 Marks)
# 
# 1. The **create_user** function requires that filename is opened in append mode in order to add a username/password combinations to filename. What will happen if filename is instead opened in write mode? Assume you are forced to use any access mode other append. Is it possible to re-write the function such that the functionality does not change? Please explain.
# 
# 
# 2. Assume you have to write a function **valid_length** that would check if the *username* and *password* are greater than 6 characters. How would you implement this function?
# 
# 
# 3. Assume you have two functions **encrypt(password)** and **decrypt(encoded_password)**. The function **encrypt** takes a password string and returns an encoded version of the password as a string. The function **decrypt** decodes  the encoded_password string and returns the decoded password as a string. Where would you use these functions in your code if you wanted your login system to store encoded user passwords rather than raw text passwords?
# 
# Please answer all questions in the cell below!

# ```
# DOUBLE CLICK TO EDIT THIS CELL. DO NOT DELETE QUOTATION MARKS
# ```
# 
# 1. If the filename is instead opened in write mode this will lead to overriding the whole file, essentailly erasing it. instead we would have to write code that splits the list into a variable and then from there on we can append the new data to the list with write mode. 
# 
# 2. we can do this by defining the function: 
#     def valid_length: 
#         if len(username) && len(password) >= 6:
#         return True
#         else: 
#         return False: 
#        What this function will do is that it will check the string length of both username and password and check if both there legnths are equal to or greater then 6 and if it is it will return true otherwise it will return false. 
# 
# 3. I would use this function somewhere in the creatingUser function, this is because this is the where the user has input in which username and password are stored in a variable and it would be the logical and easier way to encrypt the passwords. 

# ---
# ## Submission
# 
# Please download this notebook as a .py file (*File* > *Download as* > *Python (.py)*) and submit it to the Computing Lab 5 dropbox on avenue with the naming convention: macID_CL5.py
# 
# #### NOTE: YOU WILL BE MARKED ON MULTIPLE ITEMS IN THIS LAB IN ADDITION TO THE FUNCTIONALITY OF YOUR CODE
#  - Variable Names
#  - Commenting
#  - General Legibility
#  - Reflective Questions
# 
# **Make sure the final version of your lab runs without errors, otherwise, you will likely receive zero.**
# 
# This assignment is due the day of your Lab section at 11:59 PM EST
# 
# Late labs will not be accepted
