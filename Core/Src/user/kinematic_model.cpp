//#include <Kinematic Model.h>
//#include <math.h>
//
////length argument at Kinematic Model.h
//
//
////The front of the car is in the positive x direction. Counterclockwise rotation is positive
////Mecanum -- Use the first quadrant as the number one position
////Mecanum_O
//void Mecanum_O::inverse_kinetics(double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP){
//	*m1_SP = ( cmd_vel.x - cmd_vel.y - cmd_vel.z*( lx + ly) )/radius;
//	*m2_SP = ( cmd_vel.x + cmd_vel.y - cmd_vel.z*( lx + ly) )/radius;
//	*m3_SP = ( cmd_vel.x - cmd_vel.y + cmd_vel.z*( lx + ly) )/radius;
//	*m4_SP = ( cmd_vel.x + cmd_vel.y + cmd_vel.z*( lx + ly) )/radius;
//}
//void Mecanum_O::forward_kinetics(double* m1_PV, double* m2_PV, double* m3_PV, double* m4_PV){
//	realspeed.x = ( *m1_PV + *m2_PV + *m3_PV + *m4_PV )/4*radius;
//	realspeed.y = ( -*m1_PV + *m2_PV - *m3_PV + *m4_PV )/4*radius;
//	realspeed.z  = ( -*m1_PV -*m2_PV + *m3_PV + *m4_PV )/(4*( lx + ly ))*radius;
//}
//
////Mecanum_X
//void Mecanum_X::inverse_kinetics(double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP){
//	*m1_SP = ( cmd_vel.x + cmd_vel.y - cmd_vel.z*( lx - ly) )/radius;
//	*m2_SP = ( cmd_vel.x - cmd_vel.y + cmd_vel.z*( lx - ly) )/radius;
//	*m3_SP = ( cmd_vel.x + cmd_vel.y + cmd_vel.z*( lx - ly) )/radius;
//	*m4_SP = ( cmd_vel.x - cmd_vel.y - cmd_vel.z*( lx - ly) )/radius;
//}
//void Mecanum_X::forward_kinetics(double* m1_PV, double* m2_PV, double* m3_PV, double* m4_PV){
//	realspeed.x = ( *m1_PV + *m2_PV + *m3_PV + *m4_PV)/4*radius;
//	realspeed.y = ( *m1_PV - *m2_PV + *m3_PV - *m4_PV)/4*radius;
//	realspeed.z  = ( -*m1_PV + *m2_PV + *m3_PV - *m4_PV)/(4*( lx - ly ))*radius;
//}
//
////omniwheel -- Use the Y-axis direction as the first position
////omni_3
//void omni_3::inverse_kinetics(double* m1_SP, double* m2_SP, double* m3_SP){
//	*m1_SP= ( cmd_vel.x - cmd_vel.z*r )/radius;
//	*m2_SP= ( -0.5*cmd_vel.x + 2/sqrt(3)*cmd_vel.y - cmd_vel.z*r )/radius;
//	*m3_SP= ( -0.5*cmd_vel.x - 2/sqrt(3)*cmd_vel.y - cmd_vel.z*r )/radius;
//}
//void omni_3::forward_kinetics(double* m1_PV, double* m2_PV, double* m3_PV){
//	realspeed.x = ( *m1_PV*2 - *m2_PV - *m3_PV )/3*radius;
//	realspeed.y = ( *m2_PV - *m3_PV )*sqrt(3)/4*radius;
//	realspeed.z  = ( -*m1_PV - *m2_PV - *m3_PV )/(3*r)*radius;
//}
//
////omni_4
//void omni_4::inverse_kinetics(double* m1_SP, double* m2_SP, double* m3_SP, double* m4_SP){
//	*m1_SP = ( cmd_vel.x - cmd_vel.z*r )/radius;
//	*m2_SP = ( cmd_vel.y - cmd_vel.z*r )/radius;
//	*m3_SP = ( -cmd_vel.x - cmd_vel.z*r )/radius;
//	*m4_SP = ( -cmd_vel.y - cmd_vel.z*r )/radius;
//}
//void omni_4::forward_kinetics(double* m1_PV, double* m2_PV, double* m3_PV, double* m4_PV){
//	realspeed.x = ( *m1_PV - *m3_PV )/2*radius;
//	realspeed.y = ( *m2_PV - *m4_PV )*sqrt(3)/2*radius;
//	realspeed.z  = ( -*m1_PV - *m2_PV - *m3_PV - *m4_PV )/(4*r)*radius;
//}
//
////differential_wheel -- Use the Y-axis direction as the first position
//void differential_wheel::inverse_kinetics(double* m1_SP, double* m2_SP){
//	*m1_SP = ( cmd_vel.x - cmd_vel.z*r )/radius;
//	*m2_SP = ( -cmd_vel.y - cmd_vel.z*r )/radius;
//}
//void differential_wheel::forward_kinetics(double* m1_PV, double* m2_PV){
//	realspeed.x = ( *m1_PV - *m2_PV )/2*radius;
//	realspeed.z  = ( -*m1_PV - *m2_PV )/(2*r)*radius;
//}
//