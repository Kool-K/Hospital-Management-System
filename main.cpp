#include "HospitalManagement.h"
#include "Display.h"

void admin_functions(HospitalManagement& hospital) {
    int admin_choice;
    do {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add Patient\n2. Add Doctor\n3. Show All Patients\n4. Show All Doctors\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> admin_choice;

        switch (admin_choice) {
            case 1:
                hospital.add_patient();
                break;
            case 2:
                hospital.add_doctor();
                break;
            case 3:
                display_all_patients(hospital);
                break;
            case 4:
                display_all_doctors(hospital);
                break;
            case 5:
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (admin_choice != 5);
}

void doctor_functions(HospitalManagement& hospital) {
    int doctor_choice;
    do {
        cout << "\nDoctor Menu:\n";
        cout << "1. Show All Patients\n2. Show All Appointments\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> doctor_choice;

        switch (doctor_choice) {
            case 1:
                display_all_patients(hospital);
                break;
            case 2:
                display_all_appointments(hospital);
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (doctor_choice != 3);
}

void receptionist_functions(HospitalManagement& hospital) {
    int receptionist_choice;
    do {
        cout << "\nReceptionist Menu:\n";
        cout << "1. Schedule Appointment\n2. Show All Patients\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> receptionist_choice;

        switch (receptionist_choice) {
            case 1:
                hospital.schedule_appointment();
                break;
            case 2:
                display_all_patients(hospital);
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (receptionist_choice != 3);
}

void patient_functions(HospitalManagement& hospital) {
    int patient_choice;
    int patient_id;
    
    cout << "Enter your Patient ID: ";
    cin >> patient_id;

    do {
        cout << "\nPatient Menu:\n";
        cout << "1. View Bills\n2. View Appointment\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> patient_choice;

        switch (patient_choice) {
            case 1:
                display_all_bills(hospital);  // Assuming a function to view all bills
                break;
            case 2:
                hospital.show_patient_appointment(patient_id);  // New functionality to view appointment
                break;
            case 3:
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }
    } while (patient_choice != 3);
}


int main() {
    HospitalManagement hospital;  // Automatically calls the constructor to initialize the system
    hospital.load_data();         // Load any saved data from the file
    string role;

    do {
        cout << "Enter your role (admin/doctor/receptionist/patient/exit): ";
        cin >> role;

        if (role == "admin") {
            admin_functions(hospital);
        } else if (role == "doctor") {
            doctor_functions(hospital);
        } else if (role == "receptionist") {
            receptionist_functions(hospital);
        } else if (role == "patient") {
            patient_functions(hospital);
        } else if (role != "exit") {
            cout << "Invalid role!\n";
        }

    } while (role != "exit");

    return 0;
}
