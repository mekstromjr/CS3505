/**
* Michael Ekstrom
* CS3505
* A2: Making a Class
*/
#ifndef SINE_H
#define SINE_H

#include <iostream>

class Sine {
    private:
        /// @brief Current angle of the sine function in DEGREES
        double angle;
        /// @brief The amplitude is the height from the curve center line to the peak.
        double amplitude;
        /// @brief The wavelength is the horizontal distance between curve peaks in degrees.
        double wavelength;
        /// @brief This specifies the change in angle as points are plotted on the sine curve in DEGREES.
        double increment;

        /// @brief Returns the given degree value in radians
        /// @param degree - value to be converted to radians.
        /// @return Input value converted to radians.
        double convertDegreeToRadian(double degree);

    public:
        /// @brief Sine object constructor.
        /// @param amplitude - The height of the sine wave.
        /// @param wavelength - The distance between wave peaks in DEGREES.
        /// @param increment - The desired increment for the function in DEGREES. 
        Sine(double amplitude, double wavelength, double increment);

        /// @brief Sine object destructor
        ~Sine();

        /// @brief Gets the current angle (X value) of the Sine function
        /// @return The double value of the current angle.
        double currentAngle();

        /// @brief Gets the current height (Y value) of the function.
        /// @return The double value of the current function height.
        double currentHeight();

        /// @brief Overloaded pre-increment operator to move angle forward by the increment value
        /// @return This sine function after incrementing
        Sine& operator++();

        /// @brief Overloaded post-increment operator to move angle forward by increment value
        /// @return A sine object before the increment has taken place
        Sine operator++(int);

        /// @brief Overloads insertion operator for easy output of the function's current value.
        /// @param output - The output stream to insert into.
        /// @return The output stream with the functions "current angle, height" inserted.
        friend std::ostream& operator<<(std::ostream& output, Sine s);
};

#endif