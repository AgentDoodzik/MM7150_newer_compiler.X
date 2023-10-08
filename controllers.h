/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.h

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef CONTROLLERS_H    /* Guard against multiple inclusion */
#define CONTROLLERS_H

float Pitch_control(float meas_air_spd, float meas_IMU_pitch);
float Flaps_control(float meas_air_spd);
float Yaw_control(float yaw_out);
float Roll_control();
uint16_t PWM_sine_wave(uint8_t on, int16_t phase_shift)



#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
