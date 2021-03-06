#ifndef __MAC_ADDR_CPP__
#define __MAC_ADDR_CPP__

#include "MAC_addr.h"
#include <cstdio>

MAC_addr& MAC_addr::operator = (const char *rhs) {
	sscanf(rhs, "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx", &_mac[0], &_mac[1], &_mac[2], &_mac[3], &_mac[4], &_mac[5]);
	return *this;
};

MAC_addr& MAC_addr::operator = (const string& rhs) {
	const char *c = rhs.c_str();
	*this = c;
	return *this;
};

void MAC_addr::hex_dump() {
	printf("%02X:%02X:%02X:%02X:%02X:%02X", _mac[0],_mac[1],_mac[2],_mac[3],_mac[4],_mac[5]);
}

void MAC_addr::write_mem(uint8_t *mem) {
	memcpy(mem, _mac, 6);
}

bool MAC_addr::is_equal(char *mem) {
	for (int i=0; i < 6; i++) {
		if (_mac[i] != mem[i])
			return false;
	}
	return true;
}
void MAC_addr::parse_mem(char *mem) {
	for (int i=0; i < 6; i++) {
		_mac[i] = mem[i];
	}
}
void MAC_addr::parse_mem(uint8_t *mem) {
	for (int i=0; i < 6; i++) {
		_mac[i] = mem[i];
	}
}
#endif