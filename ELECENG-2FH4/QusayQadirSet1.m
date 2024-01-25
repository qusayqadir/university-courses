%Setting up the vectors 

Origin=[ 0 0 0 ];
P_1 = [ 1 2 3]; % Point one
R_1 = P_1 - Origin; % Makes the vector from the origin to the point 

P_2 = [ 3 2 1];
R_2 =  P_2 - Origin;


% A) Finding the dot product from between R_1 and R_2 

R_1_dot_R_2 = dot(R_1, R_2); 

% B) Finding the projection between R1 and R2
%using the method
%projection = (length of R_1 dot with direction of R2) * direction of R_2 

unit_vector_R_2 = R_2 / norm(R_2);  
Projection_R_1_onto_R_2 = (dot(R_1,unit_vector_R_2)) * unit_vector_R_2; 

% C) Finding the angle betwen R1 and R2
COS_theta = dot(R_1,R_2)/ (norm(R_1)*norm(R_2)); 
theta = acos(COS_theta); 
deg_theta = theta / pi * 180; 



