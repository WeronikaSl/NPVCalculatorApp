#pragma once
#include <vector>

using YearsOfInvestment = int16_t;
using CashFlows = std::vector<int64_t>; //should this be a map? year key - amount of money value
using DiscountRate = float;

enum class Language {POLISH = 1, ENGLISH};