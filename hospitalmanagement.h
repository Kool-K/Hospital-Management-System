#ifndef HOSPITAL_MANAGEMENT_H
#define HOSPITAL_MANAGEMENT_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream> // Include for string stream
using namespace std;

// Base Class
class Hospital {
public:
    Hospital() {
        cout << "Hospital system initialized.\n";
    }

    virtual void display_info() const = 0;  // Pure virtual function for polymorphism
};

// Derived Class: Patient
class Patient : public Hospital {
public:
    int id;
    string name;
    int age;
    string disease;

    Patient(int id, string name, int age, string disease)
        : id(id), name(name), age(age), disease(disease) {}

    void add_patient();
    void display_info() const override;  // Overriding base class function

    string to_string() const; // Add this method to convert to string for saving
};

// Derived Class: Doctor
class Doctor : public Hospital {
public:
    int id;
    string name;
    string specialty;

    Doctor(int id, string name, string specialty)
        : id(id), name(name), specialty(specialty) {}

    void add_doctor();
    void display_info() const override;

    string to_string() const; // Add this method to convert to string for saving
};

// Derived Class: Appointment
class Appointment : public Hospital {
public:
    int patient_id;
    int doctor_id;
    string date;

    Appointment(int patient_id, int doctor_id, string date)
        : patient_id(patient_id), doctor_id(doctor_id), date(date) {}

    void schedule_appointment();
    void display_info() const override;

    string to_string() const; // Add this method to convert to string for saving
};

// Derived Class: Billing
class Billing : public Hospital {
public:
    int patient_id;
    float amount;

    Billing(int patient_id, float amount)
        : patient_id(patient_id), amount(amount) {}

    void generate_bill();
    void display_info() const override;

    string to_string() const; // Add this method to convert to string for saving
};

// Hospital management class containing vectors of patients, doctors, appointments, and bills
class HospitalManagement {
public:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
    vector<Billing> bills;

    HospitalManagement() {
        cout << "Hospital management system initialized.\n";
    }

    void load_data();
    void save_data();
    void add_patient();
    void add_doctor();
    void schedule_appointment();
    void generate_bill();
    void show_all_patients() const;
    void show_all_doctors() const;
    void show_all_appointments() const;
    void show_all_bills() const;
    void show_patient_appointment(int patient_id) const;

};

#endif
