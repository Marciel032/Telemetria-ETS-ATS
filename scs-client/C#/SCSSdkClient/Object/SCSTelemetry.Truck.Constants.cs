﻿namespace SCSSdkClient.Object {
    public partial class SCSTelemetry {
        public partial class Truck {
            /// <summary>
            ///     Config values
            /// </summary>
            public class Constants {
                public Constants() {
                    MotorValues = new Motor();
                    CapacityValues = new Capacity();
                    WarningFactorValues = new WarningFactor();
                    WheelsValues = new WheelsConstants();
                }

                public Motor MotorValues { get; internal set; }
                public Capacity CapacityValues { get; internal set; }
                public WarningFactor WarningFactorValues { get; internal set; }
                public WheelsConstants WheelsValues { get; internal set; }

                /// <summary>
                ///     Brand id for configuration purposes.
                ///     Limited to C-identifier characters
                /// </summary>
                public string BrandId { get; internal set; }

                /// <summary>
                ///     Brand for display purposes.
                /// </summary>
                public string Brand { get; internal set; }

                /// <summary>
                ///     Name for internal use by code.
                ///     Limited to C-identifier characters and dots.
                /// </summary>
                public string Id { get; internal set; }

                /// <summary>
                ///     Name for display purposes
                ///     Localized using the current in-game language
                /// </summary>
                public string Name { get; internal set; }

                /// <summary>
                ///     Gear, Retarder, etc.
                /// </summary>
                public class Motor {
                    /// About: RetarderStepCount
                    
                    /// Set to zero if retarder is not mounted on the truck
                    /// <summary>
                    ///     Number of forward gears on undamaged truck
                    /// </summary>
                    public uint ForwardGearCount { get; internal set; }

                    /// <summary>
                    ///     Number of reverse gears on undamaged truck
                    /// </summary>
                    public uint ReverseGearCount { get; internal set; }

                    /// <summary>
                    ///     Number of steps in the retarder
                    /// </summary>
                    /// <!---->
                    /// **INFORMATION**
                    /// <!---->
                    /// Set to zero if retarder is not mounted on the truck
                    /// <!---->
                    /// **INFORMATION**
                    /// <!---->
                    public uint RetarderStepCount { get; internal set; }

                    /// <summary>
                    ///     Number of selectors (e.g. range/splitters toggles)
                    /// </summary>
                    public uint SelectorCount { get; internal set; }

                    /// <summary>
                    ///     Gear selected when requirements for this h-shifter slot are meet.
                    /// </summary>
                    public int[] SlotGear { get; internal set; }

                    /// <summary>
                    ///     Position of h-shifter handle.
                    ///     Zero corresponds to neutral position. Mapping to physical position of
                    ///     the handle depends on input setup.
                    /// </summary>

                    public uint[] SlotHandlePosition { get; internal set; }

                    /// <summary>
                    ///     Bitmask of required on/off state of selectors.
                    ///     Only first selector_count bits are relevant.
                    /// </summary>
                    public uint[] SlotSelectors { get; internal set; }

                    /// <summary>
                    ///     Maximal rpm value.
                    /// </summary>
                    public float EngineRpmMax { get; internal set; }

                    /// <summary>
                    ///     Differential ratio of the truck.
                    /// </summary>
                    public float DifferentialRation { get; internal set; }

                    /// <summary>
                    ///     Forward transmission ratios
                    /// </summary>
                    public float[] GearRatiosForward { get; internal set; }

                    /// <summary>
                    ///     Reverse transmission ratios
                    /// </summary>
                    public float[] GearRatiosReverse { get; internal set; }

                    /// <summary>
                    ///     Type of the shifter.
                    /// </summary>
                    public ShifterType ShifterTypeValue { get; internal set; }
                }


                /// <summary>
                ///     Fuel, Adblue, etc.
                /// </summary>
                public class Capacity {
                    /// <summary>
                    ///     Fuel tank capacity in litres.
                    /// </summary>
                    public float Fuel { get; internal set; }

                    /// <summary>
                    ///     AdBlue tank capacity in litres.
                    /// </summary>
                    public float AdBlue { get; internal set; }
                }

                /// <summary>
                ///     At which value X give a warning?
                /// </summary>
                public class WarningFactor {
                    /// <summary>
                    ///     Fraction of the fuel capacity bellow which is activated the fuel warning.
                    /// </summary>
                    public float Fuel { get; internal set; }

                    /// <summary>
                    ///     Fraction of the adblue capacity bellow which is activated the adblue warning.
                    /// </summary>
                    public float AdBlue { get; internal set; }

                    /// <summary>
                    ///     Pressure of the air in the tank bellow which the warning activates
                    /// </summary>
                    public float AirPressure { get; internal set; }

                    /// <summary>
                    ///     Pressure of the air in the tank bellow which the emergency brakes activate
                    /// </summary>
                    public float AirPressureEmergency { get; internal set; }

                    /// <summary>
                    ///     Pressure of the oil bellow which the warning activates.
                    /// </summary>
                    public float OilPressure { get; internal set; }

                    /// <summary>
                    ///     Temperature of the water above which the warning activates.
                    /// </summary>
                    public float WaterTemperature { get; internal set; }

                    /// <summary>
                    ///     Voltage of the battery bellow which the warning activates.
                    /// </summary>
                    public float BatteryVoltage { get; internal set; }
                }
            }
        }
    }
}