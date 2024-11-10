#ifndef _PID_CONTROLLER_HPP_
#define _PID_CONTROLLER_HPP_

namespace pid_controller
{
    struct PidParameters
    {
        /* Classic PID coefficients */
        double proportional_coef_ = 0;
        double derivative_coef_ = 0;
        double integral_coef_ = 0;

        /* Limit for integration term */
        double integration_limit_ = 0;
    };

    struct PidScales
    {
        /* Proportional and derivative scales, can be changed in every control call */
        double proportional_scale_ = 1;
        double derivative_scale_ = 1;
    };

    class PidController
    {
        private:

        PidParameters pid_params_;

        PidScales pid_scales_;


        /* Position integrator, updated in every control call */
        double position_integrator_;

        /* Time step (inverse of frequency)*/
        double time_step_;

        double calculateProportionalEffort(double _position_error); 
        double calculateIntegralEffort(double _position_error);
        double calculateDerivativeEffort(double _velocity_error);


        public:

        PidController(PidParameters _pid_params, double _frequency);
        PidController(const PidController& other) = default;
        PidController(PidController&& other) = default;

        double calculateEffort(double _position_error, double _velocity_error,
         double _feedforward_effort, PidScales _pid_scales); //  Tutaj liczymy wszystko
    };
};
#endif