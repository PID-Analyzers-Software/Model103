#pragma once

class Gas
{
	String m_name;	
	double m_intercept;
	double m_slope;
	
public:
    void setIntercept(double i) { m_intercept = i; }
    void setSlope(double p) { m_slope = p; }

    double calculateSLM(int voltage) {
		return (voltage + m_intercept ) / m_slope;
    }
};