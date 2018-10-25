#ifndef SCS_TELEMETRY_COMMON_HPP
#define SCS_TELEMETRY_COMMON_HPP

// This file contains "Common definitions" for this ETS2 telemetry plug-in.
// This includes:
// - Debug logging detail options
// - Shared memory map struct layout
// - [..]

#define PLUGIN_REVID					8

#define ETS2_PLUGIN_LOGGING_ON				0
#define ETS2_PLUGIN_LOGGING_SHAREDMEMORY	0
#define ETS2_PLUGIN_FILENAME_PREFIX "C:\ets2telem_"

#if ETS2_PLUGIN_LOGGING_ON == 1
#define SDK_ENABLE_LOGGING
#endif


#define SCS_PLUGIN_MMF_NAME TEXT("Local\\SimTelemetrySCS")
#define SCS_PLUGIN_MMF_SIZE (16*1024)
/**
 * \brief string size for all strings (most of them) the amount of fields in the shared memory field
 */
#define stringsize  64

 /**
  * \brief Actual used wheel size of the SDK   not the amount of fields in the shared memory field
  */
#define WHEEL_SIZE 14


  /**
   *  \brief Telemetry object
   *
   * instead to use a clear object like that in c# we want to create this one easy to parse and modifyable
   *
   * Look in the c header of the sdk for more desription or in the c# description
   *
   * Arrays must be set here and have all local parameter for their size
   */
typedef struct scsTelemetryMap_s
{
	//----- START OF FIRST ZONE AT OFFSET 0 -----//
	// Staring with values needed to handle the data
	// not the game time, only a timestamp. Used to update the values on the other site of the shared memory
	unsigned int time;
	// check if the game and the telemetry is paused
	bool paused;

	// to make a buffer for changes here and avoid errors later we create a empty room so we fill the first 40 fields, shrink it when you add something above here
	char buffer[35];

	//----- END OF FIRST ZONE AT OFFSET 39 -----//

	//----- START OF SECOND ZONE AT OFFSET 40 -----//
	// The Secon zone contains unsigned integers and it sorted in sub structures

	// Contains Game independent values and plugin version
	struct
	{
		// Telemetry Plugin Version
		unsigned int telemetry_plugin_revision;
		// Game major version
		unsigned int version_major;
		// Game minor version
		unsigned int version_minor;
		// Game identifier
		unsigned int game; // actually 0 for unknown,1 for ets2 and 2 for ats
		// Game telemetry version major
		unsigned int telemetry_version_game_major;
		// Game telemetry version minor
		unsigned int telemetry_version_game_minor;
	} scs_values;

	// Contains common unsigned integers
	struct {
		// In game time in minutes
		unsigned int time_abs;
	}common_ui;

	// Contains config unsigned integers
	struct {
		unsigned int gears;
		unsigned int gears_reverse;
		unsigned int retarderStepCount;
		unsigned int wheelCount;
		unsigned int selectorCount;
		unsigned int time_abs_delivery;
	}config_ui;

	// Contains trailer/truck channel unsigned integers
	struct {
		unsigned int shifterSlot;
		unsigned int retarderBrake;
		unsigned int lightsAuxFront;
		unsigned int lightsAuxRoof;
		unsigned int trailer_wheelSubstance[16];
		unsigned int truck_wheelSubstance[16];
	}truck_ui;

	char buffer_ui[44];
	//----- END OF SECOND ZONE AT OFFSET 279 -----//

	//----- START OF Third ZONE AT OFFSET 280 -----//
	// The third zone contains integers and it sorted in sub structures

	struct {
		int restStop;
	}common_i;

	struct {
		int gear;
		int gearDashboard;
	}truck_i;

	char buffer_i[28];
	//----- END OF third ZONE AT OFFSET 319 -----//

	//----- START OF FOURTH ZONE AT OFFSET 320 -----//
	// The fourth zone contains floats and it sorted in sub structures

	struct {
		float scale;
	}common_f;

	struct {
		float fuelCapacity;
		float fuelWarningFactor;
		float adblueCapacity;
		float adblueWarningFactor;
		float airPressureWarning;
		float airPressurEmergency;
		float oilPressureWarning;
		float waterTemperatureWarning;
		float batteryVoltageWarning;
		float engineRpmMax;
		float gearDifferential;
		float trailerMass;
		float wheelRadius[16];
		float gearRatiosForward[24];
		float gearRatiosReverse[8];
	}config_f;

	struct {
		float speed;
		float engineRpm;
		float userSteer;
		float userThrottle;
		float userBrake;
		float userClutch;
		float gameSteer;
		float gameThrottle;
		float gameBrake;
		float gameClutch;
		float cruiseControlSpeed;
		float airPressure;
		float brakeTemperature;
		float fuel;
		float fuelAvgConsumption;
		float fuelRange;
		float adblue;
		float oilPressure;
		float oilTemperature;
		float waterTemperature;
		float batteryVoltage;
		float lightsDashboard;
		float wearEngine;
		float wearTransmission;
		float wearCabin;
		float wearChassis;
		float wearWheels;
		float wearTrailer;
		float truckOdometer;
		float routeDistance;
		float routeTime;
		float speedLimit;
		float trailer_wheelSuspDeflection[16];
		float truck_wheelSuspDeflection[16];
		float trailer_wheelVelocity[16];
		float truck_wheelVelocity[16];
		float trailer_wheelSteering[16];
		float truck_wheelSteering[16];
		float trailer_wheelRotation[16];
		float truck_wheelRotation[16];
		float truck_wheelLift[16];
		float truck_wheelLiftOffset[16];
	}truck_f;
	char buffer_f[68];
	//----- END OF FOURTH ZONE AT OFFSET 1399 -----//

	//----- START OF FIFTH ZONE AT OFFSET 1400 -----//
	// The fifth zone contains bool and it sorted in sub structures

	struct {
		bool wheelSteerable[16];
		bool wheelSimulated[16];
		bool wheelPowered[16];
		bool wheelLiftable[16];
	}config_b;

	struct {
		bool trailer_attached;
		bool parkBrake;
		bool motorBrake;
		bool airPressureWarning;
		bool airPressureEmergency;
		bool fuelWarning;
		bool adblueWarning;
		bool oilPressureWarning;
		bool waterTemperatureWarning;
		bool batteryVoltageWarning;
		bool electricEnabled;
		bool engineEnabled;
		bool wipers;
		bool blinkerLeftActive;
		bool blinkerRightActive;
		bool blinkerLeftOn;
		bool blinkerRightOn;
		bool lightsParking;
		bool lightsBeamLow;
		bool lightsBeamHigh;
		bool lightsBeacon;
		bool lightsBrake;
		bool lightsReverse;
		bool cruiseControl; // special field not a sdk field
		bool trailer_wheelOnGround[16];
		bool truck_wheelOnGround[16];
		bool shifterToggle[2];
	}truck_b;
	char buffer_b[78];
	//----- END OF FIFTH ZONE AT OFFSET 1599 -----//

	//----- START OF SIXTH ZONE AT OFFSET 1600 -----//
	// The sixth zone contains fvector and it sorted in sub structures

	struct {
		float cabinPositionX;
		float cabinPositionY;
		float cabinPositionZ;
		float headPositionX;
		float headPositionY;
		float headPositionZ;
		float hookPositionX;
		float hookPositionY;
		float hookPositionZ;
		float wheelPositionX[16];
		float wheelPositionY[16];
		float wheelPositionZ[16];
	}config_fv;
	struct {
		float trailer_lv_accelerationX;
		float trailer_lv_accelerationY;
		float trailer_lv_accelerationZ;
		float lv_accelerationX;
		float lv_accelerationY;
		float lv_accelerationZ;
		float trailer_av_accelerationX;
		float trailer_av_accelerationY;
		float trailer_av_accelerationZ;
		float av_accelerationX;
		float av_accelerationY;
		float av_accelerationZ;
		float trailer_la_accelerationX;
		float trailer_la_accelerationY;
		float trailer_la_accelerationZ;
		float accelerationX;
		float accelerationY;
		float accelerationZ;
		float trailer_aa_accelerationX;
		float trailer_aa_accelerationY;
		float trailer_aa_accelerationZ;
		float aa_accelerationX;
		float aa_accelerationY;
		float aa_accelerationZ;
		float cabinAVX;
		float cabinAVY;
		float cabinAVZ;
		float cabinAAX;
		float cabinAAY;
		float cabinAAZ;
	}truck_fv;
	char buffer_fv[52];
	//----- END OF SIXTH ZONE AT OFFSET 1999 -----//

	//----- START OF 7TH ZONE AT OFFSET 2000 -----//
	// The 7th zone contains fplacement and it sorted in sub structures
	struct {
		float cabinOffsetX;
	    float cabinOffsetY;
	    float cabinOffsetZ;
	    float cabinOffsetrotationX;
	    float cabinOffsetrotationY;
	    float cabinOffsetrotationZ;
	    float headOffsetX;
	    float headOffsetY;
	    float headOffsetZ;
	    float headOffsetrotationX;
	    float headOffsetrotationY;
	    float headOffsetrotationZ;
	}truck_fp;
	char buffer_fp[152];
	//----- END OF 7TH ZONE AT OFFSET 2199 -----//

	//----- START OF 8TH ZONE AT OFFSET 2200 -----//
	// The 8th zone contains dplacement and it sorted in sub structures

	struct {
		double coordinateX;
		double coordinateY;
		double coordinateZ;
		double rotationX;
		double rotationY;
		double rotationZ;
		double trailer_coordinateX;
		double trailer_coordinateY;
		double trailer_coordinateZ;
		double trailer_rotationX;
		double trailer_rotationY;
		double trailer_rotationZ;
	}truck_dp;
	char buffer_dp[104];
	//----- END OF 8TH ZONE AT OFFSET 2399 -----//

	//----- START OF 9TH ZONE AT OFFSET 2400 -----//
	// The 9th zone contains strings and it sorted in sub structures

	struct {
		char truckMakeId[stringsize];
		char truckMake[stringsize];
		char Vehicle[stringsize];
		char Chassis[stringsize];
		char Cargo[stringsize];
		char truckModel[stringsize];
		char trailerId[stringsize];
		char trailerName[stringsize];
		char cityDstId[stringsize];
		char cityDst[stringsize];
		char compDstId[stringsize];
		char compDst[stringsize];
		char citySrcId[stringsize];
		char citySrc[stringsize];
		char compSrcId[stringsize];
		char compSrc[stringsize];
		char shifterType[16];
	}config_s;
	char buffer_s[760];
	//----- END OF 9TH ZONE AT OFFSET 4199 -----//

	//----- START OF 10TH ZONE AT OFFSET 4200 -----//
	// The 10th zone contains unsigned long long and it sorted in sub structures

    struct {
		unsigned long long jobIncome;
    }config_o;
	char buffer_o[192];
	//----- END OF 10TH ZONE AT OFFSET 4399 -----//

	//----- START OF 111TH ZONE AT OFFSET 4400 -----//
	// The 11th zone contains special events and it sorted in sub structures

    struct {
		bool onJob;
		bool jobFinished;
    }special_b;
	char buffer_special[198];
	//----- END OF 11TH ZONE AT OFFSET 4599 -----//
} scsTelemetryMap_t;

#endif