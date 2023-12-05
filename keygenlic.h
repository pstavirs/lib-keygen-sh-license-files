#ifndef _KEYGEN_LIC_H
#define _KEYGEN_LIC_H

#include <string>

int verify_license(
        std::string filename,
        std::string pubkey,
        std::string lickey,
        std::string *json);

int verify_machine(
        std::string filename,
        std::string pubkey,
        std::string lickey,
        std::string fingerprint,
        std::string *json);
#endif
