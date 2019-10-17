# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

### Implementation
The PID controller is implemented in PID.cpp file. The PID controller is initialized and the "cross track error" (cte) is used to calculate the steering value from it.


### PID Explanation:
P parameter - It is required to adjust the steering value in proportion to the cross track error
D parameter - Only "proprotion" characteristic is not enough as the car has the accumulated memory of direction which results in oscillating behaviour. So a "Derivative" of previous cte is taken into account to reduce the oscillation
I Parameter - Sometimes the car has some fixed bias which makes the correction done by P and D parameters ineffective. So an additional correction based on history (ie., sum) of cte is considered is provided by I parameter.


### Approach
Manual approach is used to find out and fine tune the hyperparameters (P, I, D constants). It is done in the below steps:

| P    	| I 	| D    	| Throttle                                                                                                         	| Notes                                                                                                                                                                                                                                                                                                            	|
|------	|---	|------	|------------------------------------------------------------------------------------------------------------------	|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	|
| 0    	| 0 	| 0    	| 0.30                                                                                                             	|  This makes PID output the steering value as zero.    With this values, the car is able to drive straight in straight road. The steering angle feedback received is also 0. This indicates there is no bias in the car. So the "I" constant can be set to zero always                                            	|
| 0.33 	| 0 	| 0    	| 0.30                                                                                                             	|  The range of cte is approximately -3.0 to 3 when the car is near the lane boundaries. So the initial value of P is set to 1/3 = 0.33. With this values, the car is able to turn directions when reaches the lane boundary and it keeps oscillating right from the beginning                                     	|
| 0.33 	| 0 	| 0    	| 0.05                                                                                                             	| The throttle is reduced to have finer control with the PID. With this values, the car is able to drive properly but with reduced speed.                                                                                                                                                                          	|
| 0.33 	| 0 	| 1.0  	|  if abs(cte) > 3.0, then throttle = 0.05 if 3.0 > abs(cte) > 1.5, then throttle = 0.10 otherwise throttle = 0.30 	|  Here D constant is increased to 1.0 and conditional throttle is introduced.   Because of D constant, the oscillations amplitude is reduced.   With this conditional throttle, the vehicle slows down at curves and finer control of PID controller is acheived.  But the car is still oscillating at the curves 	|
| 0.33 	| 0 	| 2.25 	| if abs(cte) > 3.0, then throttle = 0.05 if 3.0 > abs(cte) > 1.5, then throttle = 0.10 otherwise throttle = 0.30  	|  To reduce the amplitude of oscillations, it is necessary to change D.  By further increasing and fine tuning the D constant, a value of 2.25 is good enough to provide a smoother control across the complete track                                                                                             	|