#include "Figures.hpp"

Figure::Figure(const char c): symbol(c), color(c < 'a' ? 1 : 0)
{
}
