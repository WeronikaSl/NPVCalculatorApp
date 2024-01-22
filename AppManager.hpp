#pragma once

class AppManager
{
public:
	virtual ~AppManager() = default;
	virtual void useNPVCalculator() = 0;
};