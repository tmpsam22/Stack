#include <person/person_keeper.h>

// файл person_keeper.cpp содержит реализации класса PersonKeeper
namespace custom
{
namespace objects
{

PersonKeeper::PersonKeeper()
{ }

PersonKeeper::~PersonKeeper()
{ }

PersonKeeper& PersonKeeper::CreateInstance()
{
    static PersonKeeper PersonKeeper_;
    return PersonKeeper_;
}

} // namespace objects
} // namespace custom