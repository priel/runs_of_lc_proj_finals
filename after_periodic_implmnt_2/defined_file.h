#ifndef DEFINED_H_INCLUDED
#define DEFINED_H_INCLUDED
	///mathematical defined:
#define PI 3.1415926535897
#define K_B 1.38066e-23

	/// model defined:
#define MODEL_NAME "after_periodic_implmnt" ///the model name, this will be the folder name in the run directory

#define DIMENSIONS 3
#define MOLECULES_IN_EACH_DIRECTION {3,3,3} /// #moleuclues will be the product of all elements.
#define SYSTEM_SIZES {3,3,3} /// SHOULD BE INT - grid cells are 1X1X1 cubes
//the location of the molecules cant exceed the size of the system.

	/// colloid molecules location vector - define all the colloid molecules in the system
	/// the location can be outside of the system -  a colloid molecule will be added to the array of molecules
	/// and will stand alone outside the system.
	/// This option is used if we want to consider periodic potential of colloid and include colloid outside of the system "box".
#define COLLOID_MOLS {\
    {5,5,5}/*,{16,16,16},{-6,-6,-6},
	{ -6,-6,5 }, { -6,-6,16 }, { -6,5,-6 },{-6,5,5},
	{ -6,5,16 }, { -6,16,-6 }, { -6,16,5 }, 
	{ -6,16,16 }, { 5,-6,-6 }, { 5,-6,5 }, 
	{ 5,-6,16 }, { 5,5,-6 }, { 5,5,16 }, 
	{ 5,16,-6 }, { 5,16,5 }, { 5,16,16 }, 
	{ 16,-6,-6 }, { 16,-6,5 }, { 16,-6,16 }, 
	{ 16,5,-6 }, { 16,5,5 }, { 16,5,16 }, 
	{ 16,16,-6 }, { 16,16,5 }*/ \
}

	//#define IGNORE_COLLOIDS ///this defined tell the program to ignore colloid molecules, comment in order to use colloids.
#define DONT_MOVE_COLS //if this is defined then the simulation will not move colloids

//if STARTING_SYSTEM is defined the system will not get randomize according to the init but starting with the system from the xyz file.
// this will only init the LC molecules, the colloids will be added as is from here.
//don't forget to add the double slashes!
#define SARTING_SYSTEM "C:\\Users\\paharoni\\phys_proj_lc\\lc_sys_make_file\\LC_periodic\\runs\\after_periodic_implmnt\\output\\lqs_sys_0126.xyz" 


#define INIT_SPACING 1.0 ///the expected value of the inital location of the molecules
#define INIT_SPIN {1/sqrt(3), 1/sqrt(3),1/sqrt(3)} ///the expected value of the inital orientation of the molecules

#define INIT_SPACING_STD 0.1 ///the standart deviation of the inital location of the location
#define INIT_SPIN_STD 1.0 ///the standart deviation of the inital location of the spin
	//can't be zero!

#define TEMPERATURE_RANGE {3.0, 2.9,2.8,2.7,2.6, 2.5,2.4,2.3,2.2,2.1, 2.0, 1.9,1.8,1.7,1.6, 1.5,1.4,1.3,1.2,1.1, 1.0, 0.9, 0.8, 0.7, 0.6, 0.5,0.5,0.5,0.5, 0.5,0.5,0.5,0.5, 0.4,0.4,0.4,0.4,0.4, 0.4,0.4,0.4,0.4,0.4, 0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3, 0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2,0.2, 0.1,0.1,0.1,0.1,0.1, 0.1,0.1,0.1,0.1,0.1,0.09,0.09,0.09,0.09,0.09,0.08,0.08,0.08,0.08,0.08,0.07,0.07,0.07,0.07,0.07,0.06,0.06,0.06,0.06,0.06,0.05,0.05,0.05,0.05,0.05, 0.04,0.04,0.04,0.04,0.04,0.03,0.03,0.03,0.03,0.03,0.02,0.02,0.02,0.02,0.02,0.01,0.01,0.01,0.01,0.01,0.009,0.008,0.007,0.006,0.005,0.004,0.002, 0.001}  ///temperature range of the monte carlo

#define NUMBER_OF_STEPS 100 ///number of steps in each temperature

#define STD_LOCATION 0.2 ///the standart deviation of the location in the monte carlo
#define STD_SPIN 0.05 ///the standart deviation of the orientation in the monte carlo
	//can't be zero!

	//L > D
#define D_0 0.7 /// the small size of the liquid crystal molecule.
#define L_0 2.3 /// the long size of the liquid crystal molecule

#define D_1 6.0 /// the radius of the colloid molecule
#define L_1 6.001 ///D_1 + very small number, just to allow the expression (L_1 - D_1) / (L_1 - D_1)

#define BOUNDARY 1 // possible values {Box = 0, Periodic = 1}
#define RANGE 1 // number of grid cells to include in every direction in potential calculation.
				// using grid we consider only pair potential between neighbors within RANGE grid cells

#define EPSILON0_0 K_B ///the epsilon0 of the LC
#define EPSILON0_1 K_B ///the epsilon0 of the col


#define EE_DIV_ES_0 1.0 ///the ratio of the corresponding to the end-to-end arrengment vs the corosponding to the side-by-side arrangement, for the LC.
#define EE_DIV_ES_1 1.0 ///same for the colloide.

	//miu and ni are adjustable parameters
#define MIU 1.0 ///parameter taken into account the location between the molecules as well as the spin.
#define NI 1.0 ///parameter taken into account only the orientation between the molecules.

#define DIF_ANGLES_COL_REPRESENTATION 30 ///the colloide is represented by a lot of LC like molecules locating in the same place
	///this parameter influence what is the difference between each 2 lines (LC like molecules), this is in degrees.
	//the number should be divide in 180

	///programming  and debug defined:
//#define DEBUG
#define SHOW_TEMP_TIMMING
	//#define DEBUG_COUNT  //print the count of the potential (Oshri)

#define PRINT_LOG //print potential after each step of the monte carlo

	enum Mol_Type { LC, COLLOID };


#endif // DEFINED_H_INCLUDED
