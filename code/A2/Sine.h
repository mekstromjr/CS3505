#ifndef IO_STREAM
#define IO_STREAM
    #include <iostream>
#endif

class Sine {
    public:
        /// @brief Current angle of the sine function in DEGREES
        double angle;
        /// @brief The amplitude is the height from the curve center line to the peak.
        double amplitude;
        /// @brief The wavelength is the horizontal distance between curve peaks in degrees.
        double wavelength;
        /// @brief This specifies the change in angle as points are plotted on the sine curve in DEGREES.
        double increment;

        /// @brief 
        /// @param amplitude 
        /// @param wavelength 
        /// @param increment - The desired increment for the function in DEGREES
        Sine(double amplitude, double wavelength, double increment);

        // ~Sine();

        /// @brief 
        /// @return 
        double currentAngle();

        /// @brief Gets the current height (Y value) of the function.
        /// @return 
        double currentHeight();

        /// @brief Overloaded pre-increment operator to move angle forward by the increment value
        /// @return 
        Sine& operator++();

        /// @brief 
        /// @param  
        /// @return 
        Sine& operator++(int);
        /// @brief 
        /// @param os 
        /// @return 
        friend std::ostream& operator<<(std::ostream& output, Sine s);

        /// @brief 
        /// @param degree 
        /// @return 
        double degreeToRadian(double degree);
};