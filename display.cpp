#include "Display.h"

// Display all patients using polymorphic `display_info()` method
void display_all_patients(const HospitalManagement& hospital) {
    cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Age" << setw(20) << "Disease" << endl;
    hospital.show_all_patients();
}

// Display all doctors using polymorphic `display_info()` method
void display_all_doctors(const HospitalManagement& hospital) {
    cout << left << setw(10) << "Doctor ID" << setw(20) << "Doctor Name" << setw(20) << "Specialty" << endl;
    hospital.show_all_doctors();
}

// Display all appointments using polymorphic `display_info()` method
void display_all_appointments(const HospitalManagement& hospital) {
    cout << left << setw(10) << "Patient ID" << setw(10) << "Doctor ID" << setw(20) << "Appointment Date" << endl;
    hospital.show_all_appointments();
}

// Display all bills using polymorphic `display_info()` method
void display_all_bills(const HospitalManagement& hospital) {
    cout << left << setw(10) << "Patient ID" << setw(15) << "Amount" << endl;
    hospital.show_all_bills();
}
