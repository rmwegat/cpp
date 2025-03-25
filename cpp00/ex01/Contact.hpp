#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;

    public:
        Contact(void);
        ~Contact(void);

        // Getters
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickname(void) const;
        std::string getPhoneNumber(void) const;
        std::string getDarkestSecret(void) const;

        // Setters
        void setFirstName(const std::string &firstName);
        void setLastName(const std::string &lastName);
        void setNickname(const std::string &nickname);
        void setPhoneNumber(const std::string &phoneNumber);
        void setDarkestSecret(const std::string &darkestSecret);
};

#endif