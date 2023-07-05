#!/usr/bin/env python
# coding: utf-8

# # Computing 8 Assignment
# 

# ---
# ## Background
# 
# Object oriented programming languages are often used when designing and developing complex systems such as movement systems for a robot. In this assignment, you will be implementing a **Drone** class for a robot. Flying drones such as quadcopters are now commonplace with many consumers. Our class will help keep track of the properties of our drone, and its location in space. Specifically, we will track.
# 
# -	The drones’s name
# -	The drone's battery percentage
# -	The drones’s X coordinate in space
# -   The drone's Y coordinate in space
# -   The drone's altitude in space
# 
# Our movement system for our drone can be thought of as an infinitely large grid, where [0,0] is the respective **X** and **Y** coordinates of our drone in its starting position. Additionally, we also have a third dimension (**Z**) which is the altitude of the drone, which can be only 0 or greater. 
# 
# You will also be required to write a **function** that utilizes your **Drone** class, the details of which are provided in your Program Requirements below. 

# ### ---
# ## Program Requirements (12 Marks)
# 
# ### Requirements - Drone Class
# 
# The requirements for the **Drone** class are given below. Please ensure that your methods have the EXACT naming as specified! Failure to do so will result in lost marks.
# 
# ***Note: you must include a try and except statement in at least one method in your code.***
# 
# 1.	Create an **\_\_init\_\_**(*name*) method that takes the following arguments:
# 
#     ***name***: A *string* representing the name of the Drone. The variable is assigned to an instance variable. If *name* is an empty string, the instance variable is set to the string **"Default"**.
#     
#     The method also initializes the following instance variables:
#     
#     - An *int* representing the drones’s battery. The drones’s battery is initially set to **100**.  
#     - An *int* representing the drones’s X coordinate. The drones’s initial X coordinate is **0**.  
#     - An *int* representing the drones’s Y coordinate. The drones’s initial Y coordinate is **0**.
#     - A *string* representing the drones’s altitude in meters. The drones’s initial altitude coordinate is **0m**.
# 
# 
# 2.	Create the following **accessor** methods:
# 
#     -	**get_name**: Returns the Drones’s name.  
#     -	**get_X**: Returns the drone's X coordinate
#     -	**get_Y**: Returns the drone's Y coordinate 
#     -	**get_coords**: Returns the drone's X and Y coordinates in the list format: [X,Y]
#     -	**get_altitude**: Returns the drone's altitude
#     -	**get_charge**: Returns the drone's current battery life
#     
#     
# 3.	Create the **mutator** method *charge*()
#     -	**Method description**: The method does not return anything, but sets the drone's battery to **100**.
#     
#     
#     
# 4.	Create the **mutator** method **move_x**(*val*) 
#     -	***val***: An *int*.  
#     -	**Method description**: The method does not return anything, but moves the drone's X coordinate by **val**. **val** can be a positive or negative number. Note that this method moves the drone *relative* to it's current positon. If the drone's current X coordinate is **3**, moving the drone by +5 will set the new X coordinate to **8**.
#     - This method drains the drone's battery life by **5**. Ensure the battery value does not turn negative as 0 is the lowest possible battery life.
#     - **IMPORANT**: If the drone's battery life is **0**, this method does not move the drone, and instead returns the following message:
#     <center>"Error - Please charge the drone"</center>
#     
#     
# 5.	Create the **mutator** method **move_y**(*val*) 
#     -	***val***: An *int*.  
#     -	**Method description**: The method does not return anything, but moves the drone's Y coordinate by **val**. **val** can be a positive or negative number. Note that this method moves the drone *relative* to it's current positon. If the drone's current Y coordinate is **-10**, moving the drone by -7 will set the new Y coordinate to **-17**.
#     - This method also drains the drone's battery life by **5**. Ensure the battery value does not turn negative as 0 is the lowest possible battery life.
#     - **IMPORANT**: If the drone's battery life is **0**, this method does not move the drone, and instead returns the following message:
#     <center>"Error - Please charge the drone"</center>
#     
#     
# 6.	Create the **mutator** method **fly_to**(*new_x*,*new_y*)
#     -	**Method description**: The method does not return anything, but instead **sets** the drone's X and Y coordinates to **new_x** and **new_y** respectively. **new_x** and **new_y** can be positive or negative numbers. This method overwrites the drone's current coordinates.
#     - This method also drains the drone's battery life by **10**. Ensure the battery value does not turn negative as 0 is the lowest possible battery life.
#     - **IMPORANT**: If the drone's battery life is **0**, this method does not move the drone, and instead returns the following message:
#     <center>"Error - Please charge the drone"</center>
#     
# 7.	Create the **mutator** method **move_altitude**(*height*)
#     -   ***height***: An *int*.
#     -   **Method description**: The method adds or subtracts the current altitude of the drone by **height**, and returns the new altitude of the drone as a string. If the new altitude is **negative**, the method sets the drone's altitude to 0 instead.
#     - This method also drains the drone's battery life by **15**.
#     - **IMPORANT**: If the drone's battery life is **0**, this method does not move the drone, and instead returns the following message:
#     <center>"Error - Please charge the drone"</center>
#  
# 
# **WE HAVE SAID THIS 5 TIMES ALREADY --- THE DRONE WILL MOVE AS LONG AS THE BATTERY IS NOT ZERO. THE BATTERY PERCENT CANNOT BECOME NEGATIVE. FOR EXAMPLE :: 5% - 10% = 0%**
#  
#  
# --- 
# ### Requirements -  Class Function
# You are also required, in a seperate cell, to create a **function** that will utilize your **Drone** class.
# 
# 1.	Define the function **evasive_maneuvers**(*drone1*,*e_x*,*e_y*)
#     -   **drone1**: A *Drone* object
#     -   ***e_x***: An *int*.
#     -   ***e_y***: An *int*.
#     -   **Function description**: This function makes the drone perform an evasive maneuver, which consists of **5 movements**. For each of the **5 movements**, the X, Y, and altitude values follow the values below:
#     
#         - The X coordinate of the drone oscillates between having *e_x* added to it, and then subtracted from it **5 times**. For example, if the initial X coordinate of the drone was 3, and *e_x* was 4, the 5 X coordinate movements would be: <u>7, 3, 7, 3, 7</u>
#          - The Y coordinate of the drone has *e_y* continuously subtracted from it **5 times**. For example, if the initial Y coordinate of the drone was 10, and *e_y* was 5, the 5 Y coordinate movements would be: <u>5, 0, -5, -10, -15</u>
#          - The function should return all sets of X and Y coordinates as a **list of lists** . For example:
#          [[7,5], [3,0], [7,-5], [3,-10], [7,-15]] 
#          - This function  drains the drone's battery severly by setting it to **1**.
#          - **IMPORANT**: If the drone's battery life is **0**, this function does not move the drone, and instead returns the following message:
#     <center>"Error - Please charge the drone"</center>
#          

# ---
# ## Implementation
# Please define the Drone class in the cell below.

# In[67]:


#********************************************
# Write your class definition and __init__ function below: (1.5 marks)
#********************************************
#The constructor method takes a parameter "name" and initializes various attributes of the drone object such as name, battery, X, Y, and Z.
class Drone:
    def __init__(self,name):
        if(name==""): 
            self.name = "Default" #If the name parameter is an empty string, it sets the name to "Default".
        else: 
            self.name = name

        self.battery = 100
        self.X = 0
        self.Y = 0
        self.Z = 0


#********************************************
# Write your accessor methods below: (0.25 marks each)
#********************************************
#These are methods that allow the user to access the different attributes of the drone object.
    def get_name(self):
        return self.name
    
    def get_X(self):
        return self.X
    def get_Y(self):
        return self.Y
    def get_coords(self):
        return [self.X, self.Y]
    def get_altitude(self):
        return {self.Z}
    def get_charge(self):
        return self.battery

#********************************************
# Write all mutator methods below: (1.5 marks each)
#********************************************
#There are methods to get the name, X and Y coordinates, altitude (Z), battery charge, and a combined method to get the X and Y coordinates as a list.    
    def charge(self):
        self.battery = 100
    
#Method to move x
    def move_x(self,val):
        try:
            if(self.battery>0):#If battery life is greater than 0, drone will move
                self.X += val
                self.battery -= 5 #each time drone moves, drains battery life by 5
                if(self.battery<0):
                    self.battery = 0 
            else:
                raise Exception()
        except:
            return "Error- Please charge the drone"

    #Method to move y
    def move_y(self,val): #code is same for moving x instaed this is for the y-direction
        try:
            if(self.battery>0):
                self.Y += val
                self.battery -= 5 
                if(self.battery<0):
                    self.battery = 0 
            else:
                raise Exception()
        except:
            return "Error- Please charge the drone"

#Method to change x and y coordinates
    def fly_to(self, new_x, new_y):
        try:
            if(self.battery>0):
                self.X = new_x #new x coordinate
                self.Y = new_y# new y coordinate
                self.battery -=10 #drains battery life by 10
                if(self.battery<0):
                    self.battery = 0
                
            else:
                raise Exception()
        except:
            return "Error- Please charge the drone"

    #Methode to chane z/altitue
    def move_altitude(self,height):
        try:
            if(self.battery>0):
                self.Z += height #increases altitude of drone
                if(self.Z<0):
                    self.Z = 0
                self.battery -= 15 #drains batteyr life by 15
                if(self.battery<0):
                    self.battery = 0
                return f'{self.Z}m' 
            else:
                raise Exception()
        except:
            return "Error- Please charge the drone"


# Please define the evasive maneuvers function in the cell below:

# In[68]:


#********************************************
# Write your evasive_maneuvers function below: (1.5 marks)
#********************************************
def evasive_maneuvers(drone1,e_x,e_y):
    if drone1.battery == 0:
        return "Error - Please charge the drone"
    position = []
    for i in range (5):
        
        if( drone1.move_x(e_x) =="Error - Please charge the drone"):
            return st
          
        
        if(drone1.move_y(-e_y)  == "Error - Please charge the drone"):
            return st
         
        
        position.append(drone1.get_coords())
        e_x *= -1
    drone1.battery = 1
    return position 


# ---
# ## Testing
# 
# The cell below contains a main function that you can use to test your functions. 
# 
# ### Important 
# Run the cell where you implemented your functions first and ensure it raises no errors. Then, run the cell below with the main function to verify that your code works correctly. The following output should be seen:
# 
# <code>
# ----TESTING CREATION----
# Drone created with name: QDrone, Coordinates: [0, 0], Altitude: 0m, and Battery life 100
# </code>
# <code>
# ----TESTING MOVEMENT----
# X movement by 7 units, Y movement by -13 units. New Coordinates: [7, -13]
# Drone elevated, now at a height of: 43m
# Current battery life: 75
# </code>
# <code>
# ----TESTING MOVEMENT----
# Drone movement. New Coordinates: [314, -201]
# Emergency Landing. Now at a height of: 0m
# Current battery life: 50
# </code>
# <code>
# ----RECHARGING AND TAKEOFF----
# Drone Recharged: 100
# Takeoff! Now at a height of: 20m - Coordinates: [314, -201]
# </code>
# <code>
# ----EVASIVE MANEUVERS ----
# [[324, -181], [314, -161], [324, -141], [314, -121], [324, -101]]
# Current Battery Life: 1
# </code>
# <code>
# ----LOW BATTERY MOVEMENTS ----
# Drone movement to home. New Coordinates: [0, 0]
# Attempting movement on emergency battery...
# Error - Please charge the drone
# Error - Please charge the drone
# Error - Please charge the drone
# Error - Please charge the drone
# Final Test: Error - Please charge the drone
# </code>
# Note that your code is not necessarily correct if your output matches the expected output. Your code will be checked against multiple inputs for correctness. The cell below is not graded, so feel free to modify the code as you wish!

# In[69]:


print("----TESTING CREATION----")
d1 = Drone("QDrone")
d1_name,d1_coords,d1_height,d1.battery = d1.get_name(),d1.get_coords(),d1.get_altitude(),d1.get_charge()

print(f"Drone created with name: {d1_name}, Coordinates: {d1_coords}, Altitude: {d1_height}, and Battery life {d1.battery}")

print("\n----TESTING MOVEMENT----")
d1.move_x(7)
d1.move_y(-13)
d1.move_altitude(43)
print(f"X movement by 7 units, Y movement by -13 units. New Coordinates: {d1.get_coords()}")
print(f"Drone elevated, now at a height of: {d1.get_altitude()}")
print(f"Current battery life: {d1.get_charge()}")

print("\n----TESTING MOVEMENT----")
d1.fly_to(314,-201)
d1.move_altitude(-100)
print(f"Drone movement. New Coordinates: {d1.get_coords()}")
print(f"Emergency Landing. Now at a height of: {d1.get_altitude()}")
print(f"Current battery life: {d1.get_charge()}")

print("\n----RECHARGING AND TAKEOFF----")
d1.charge()
print(f"Drone Recharged: {d1.get_charge()}")
d1.move_altitude(20)
print(f"Takeoff! Now at a height of: {d1.get_altitude()} - Coordinates: {d1.get_coords()}")

print("\n----EVASIVE MANEUVERS ----")
print(evasive_maneuvers(d1,10,-20))
print(f"Current Battery Life: {d1.get_charge()}")

print("\n----LOW BATTERY MOVEMENTS ----")
d1.fly_to(0,0)
print(f"Drone movement to home. New Coordinates: {d1.get_coords()}")
print(f"Attempting movement on emergency battery...")
print(d1.fly_to(10,20))
print(d1.move_x(10))
print(d1.move_y(10))
print(d1.move_altitude(10))
print("Final Test:", evasive_maneuvers(d1,20,20))


# ---
# ## Code Legibility (6 Marks)
# Your code will be marked on commenting and code legibility.<br>
# The mark breakdown is as follows:<br>
# > 2 marks for using appropriate variable names that indicate what is being stored in that variable<br>
# 2 marks for leaving comments on major parts of your code such as where you read the file or calculate a summation<br>
# 2 marks for exception handling. Your functions should produce the required outputs even when receiving unexpected inputs

# ---
# ## Test Plan (6 Marks)
# Develop a test plan for your program. Your test plan should have at least three test cases: one normal case, one boundary case, and one abnormal case. You can test any function but you must test **at least two different** functions. Please use the following format for your test cases:
# 
# **Function:**   
# **Input:**  
# **Output:**  
# **Excepted Output:**  
# **Pass/Fail:**  
# 
# An example test case is shown below:  
# ```
# Function: fly_to(self,new_x,new_y)
# Input: d = Drone("QDrone")
#        d.fly_to(10,20)
#        print(d.get_coords() == [10,20])
# Excpected Output: True
# Output: True
# Pass/Fail: Pass
# ```
# 
# Implement your testing plan in the cell below! 

# ```
# DOUBLE CLICK TO EDIT THIS CELL. DO NOT DELETE QUOTATION MARKS
# Normal Case
# Function: move_y(self,val)
# Indput: d = Drone("Drone")
#     d.move_y(50)
#     print(d.get_corrds() == [0,50])
# Output: True
# Expected Output: True
# Pass/Fail: Pass
#     
# Abnormal Case
# Function: evasive_maneuvers(drone1 , e_x, e_y ):
# Input: d=Drone("Drone)
#     d.evasive_maneuvers (drone1, -40, 3245, -32113)
# Excpected Output: Too many pareamters in method evasive_maneuvers (drone1, e_x, e_y):
# Output: Too many pareamters in method evasive_maneuvers (drone1, e_x, e_y):
# Pass/Fail: Pass 
# 
# Boundary case: 
# Function: move_x(self, val)
# Input: d = Drone("Drone")
#     d.move_x("Move Drone")
# Expected output: Value error
# Output: Value Error 
# Pass/Fail: Pass
# 
# ```

# 
# /---
# ## Reflective Questions
# 
# 1. Currently, our program does not do anything if the battery of the drone reaches 0, even if the drone is in flight. How could you implement a way to make the drone land if the battery ever reaches 0 after any movement?
# 
# 
# 2. Suppose we had a method ***rename_drone(self,name)*** that renames your drone object with *name*. Would this method be an accessor or mutator?
# 
# 
# 3. How could you modify this program to deplete the battery based on how far the drone moved in the **move_x(), move_y(), and move_altitude()** methods rather than a preset depletion everytime a movement method is called?
# 
# Please answer all questions in the cell below!

# ```
# DOUBLE CLICK TO EDIT CELL. DO NOT DELETE QUOTATION MARKS
# 
# 1. I would create a method, to indicate that the drone battery is 0. This way we can start to maneuver the drone back down before the battery goes to 0. Also if I can create a method that sends the drone back to its orginal location or fly a certain distance that can allow the drone to fly and be able to come back before the drone dies in the air. 
# 
# 2. The method rename_drone(self,name) would be a mutator because s changes the name of the  drone, instead of deteremining what is its name
# 
# 3. I would change it program by changing the drone class to that has a live update of the battery percentage of the drone after it moves a certain distance for example if it moves suppose 2m the battery would decrease by 1 percent in any direction - x y z 
# 
# ```

# ---
# ## Submission
# 
# Please download this notebook as a .py file (*File* > *Download as* > *Python (.py)*) and submit it to the Computing Lab 8 dropbox on avenue with the naming convention: macID_CL8.py
# 
# **Make sure the final version of your lab runs without errors, otherwise, you will likely recieve zero.**
# 
# This assignment is due the day of your Lab section at 11:59 PM EST
# 
# Late labs will not be accepted
