#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
private:

public:
    // Constructors
    Employee();
    Employee(const std::string& name, int id);

    // Destructor
    ~Employee();

};

#endif /* EMPLOYEE_H */
