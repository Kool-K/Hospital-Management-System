#include "HospitalManagement.h"

// Patient Methods
void Patient::add_patient() {
    cout << "Enter Patient ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Patient Name: ";
    getline(cin, name);
    cout << "Enter Patient Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Disease: ";
    getline(cin, disease);
}

void Patient::display_info() const {
    cout << left << setw(10) << id << setw(20) << name << setw(10) << age << setw(20) << disease << "\n";
}

string Patient::to_string() const {
    return std::to_string(id) + "," + name + "," + std::to_string(age) + "," + disease;
}

// Doctor Methods
void Doctor::add_doctor() {
    cout << "Enter Doctor ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Doctor Name: ";
    getline(cin, name);
    cout << "Enter Specialty: ";
    getline(cin, specialty);
}

void Doctor::display_info() const {
    cout << left << setw(10) << id << setw(20) << name << setw(20) << specialty << "\n";
}

string Doctor::to_string() const {
    return std::to_string(id) + "," + name + "," + specialty;
}

// Appointment Methods
void Appointment::schedule_appointment() {
    cout << "Enter Patient ID: ";
    cin >> patient_id;
    cout << "Enter Doctor ID: ";
    cin >> doctor_id;
    cin.ignore();
    cout << "Enter Appointment Date (DD/MM/YYYY): ";
    getline(cin, date);
}

void Appointment::display_info() const {
    cout << left << setw(10) << patient_id << setw(10) << doctor_id << setw(20) << date << "\n";
}

string Appointment::to_string() const {
    return std::to_string(patient_id) + "," + std::to_string(doctor_id) + "," + date;
}

// Billing Methods
void Billing::generate_bill() {
    cout << "Enter Patient ID: ";
    cin >> patient_id;
    cout << "Enter Amount: ";
    cin >> amount;
}

void Billing::display_info() const {
    cout << left << setw(10) << patient_id << setw(15) << amount << "\n";
}

string Billing::to_string() const {
    return std::to_string(patient_id) + "," + std::to_string(amount);
}

// Hospital Management Methods
void HospitalManagement::load_data() {
    ifstream file("hospital_data.txt");
    string line;

    // Load Patients
    while (getline(file, line) && !line.empty()) {
        istringstream ss(line);
        int id, age;
        string name, disease;
        getline(ss, line, ','); id = stoi(line);
        getline(ss, name, ',');
        getline(ss, line, ','); age = stoi(line);
        getline(ss, disease, ',');
        patients.emplace_back(id, name, age, disease);
    }

    // Load Doctors
    while (getline(file, line) && !line.empty()) {
        istringstream ss(line);
        int id;
        string name, specialty;
        getline(ss, line, ','); id = stoi(line);
        getline(ss, name, ',');
        getline(ss, specialty, ',');
        doctors.emplace_back(id, name, specialty);
    }

    // Load Appointments
    while (getline(file, line) && !line.empty()) {
        istringstream ss(line);
        int patient_id, doctor_id;
        string date;
        getline(ss, line, ','); patient_id = stoi(line);
        getline(ss, line, ','); doctor_id = stoi(line);
        getline(ss, date, ',');
        appointments.emplace_back(patient_id, doctor_id, date);
    }

    // Load Bills
    while (getline(file, line) && !line.empty()) {
        istringstream ss(line);
        int patient_id;
        float amount;
        getline(ss, line, ','); patient_id = stoi(line);
        getline(ss, line, ','); amount = stof(line);
        bills.emplace_back(patient_id, amount);
    }

    file.close();
}

void HospitalManagement::save_data() {
    ofstream file("hospital_data.txt");

    // Save Patients
    for (const auto& patient : patients) {
        file << patient.to_string() << endl;
    }
    file << endl; // Blank line to separate sections

    // Save Doctors
    for (const auto& doctor : doctors) {
        file << doctor.to_string() << endl;
    }
    file << endl; // Blank line to separate sections

    // Save Appointments
    for (const auto& appointment : appointments) {
        file << appointment.to_string() << endl;
    }
    file << endl; // Blank line to separate sections

    // Save Bills
    for (const auto& bill : bills) {
        file << bill.to_string() << endl;
    }

    file.close();
}

void HospitalManagement::add_patient() {
    int id, age;
    string name, disease;

    cout << "Enter Patient ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Patient Name: ";
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    cin.ignore();
    cout << "Enter Disease: ";
    getline(cin, disease);

    patients.emplace_back(id, name, age, disease);
    save_data();
}

void HospitalManagement::add_doctor() {
    int id;
    string name, specialty;

    cout << "Enter Doctor ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Doctor Name: ";
    getline(cin, name);
    cout << "Enter Specialty: ";
    getline(cin, specialty);

    doctors.emplace_back(id, name, specialty);
    save_data();
}

void HospitalManagement::schedule_appointment() {
    int patient_id, doctor_id;
    string date;

    cout << "Enter Patient ID: ";
    cin >> patient_id;
    cout << "Enter Doctor ID: ";
    cin >> doctor_id;
    cin.ignore();
    cout << "Enter Appointment Date (DD/MM/YYYY): ";
    getline(cin, date);

    appointments.emplace_back(patient_id, doctor_id, date);
    save_data();
}

void HospitalManagement::generate_bill() {
    int patient_id;
    float amount;

    cout << "Enter Patient ID: ";
    cin >> patient_id;
    cout << "Enter Amount: ";
    cin >> amount;

    bills.emplace_back(patient_id, amount);
    save_data();
}

void HospitalManagement::show_all_patients() const {
    for (const auto& patient : patients) {
        patient.display_info();
    }
}

void HospitalManagement::show_all_doctors() const {
    for (const auto& doctor : doctors) {
        doctor.display_info();
    }
}

void HospitalManagement::show_all_appointments() const {
    for (const auto& appointment : appointments) {
        appointment.display_info();
    }
}

void HospitalManagement::show_all_bills() const {
    for (const auto& bill : bills) {
        bill.display_info();
    }
}

void HospitalManagement::show_patient_appointment(int patient_id) const {
    bool appointment_found = false;
    for (const Appointment& appointment : appointments) {
        if (appointment.patient_id == patient_id) {
            appointment_found = true;
            cout << "Appointment Date: " << appointment.date << endl;

            for (const Doctor& doctor : doctors) {
                if (doctor.id == appointment.doctor_id) {
                    cout << "Attending Doctor: " << doctor.name << " (Specialty: " << doctor.specialty << ")" << endl;
                    break;
                }
            }
        }
    }

    if (!appointment_found) {
        cout << "No appointment found for the patient with ID " << patient_id << endl;
    }
}
