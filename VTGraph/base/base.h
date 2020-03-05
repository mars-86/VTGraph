#ifndef BASE_H
#define BASE_H
#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <cstdarg>

namespace base {

	void* strcat_all(char* dest, size_t size, const char* fmt, ...)
	{
		va_list(vl);
		va_start(vl, fmt);
		std::string s;
		while (*fmt != '\0') {
			switch (*fmt) {
			case 'c':
				s += va_arg(vl, int);
				break;
			case 'd':
				s += std::to_string(va_arg(vl, int));
				break;
			case 'l':
				s += std::to_string(va_arg(vl, long));
				break;
			case 'f':
				s += std::to_string(va_arg(vl, double));
				break;
			case 's':
				s += va_arg(vl, char*);
				break;
			default:
				++fmt;
				break;
			}
			++fmt;
		}
		if (size < s.size()) throw("BAD SIZE");
		return memcpy(dest, s.c_str(), size);
	}
	
	void reverse(char str[], int length) 
	{ 
		int start = 0; 
		int end = length - 1; 
		while (start < end) 
		{ 
			std::swap(*(str + start), *(str + end)); 
			++start; 
			--end; 
		}
	}
 	
	char* itoa(int num, char *str, int base)
	{
		int i = 0; 
		bool isNegative = false;
		/* Handle 0 explicitely, otherwise empty string is printed for 0 */
		if (num == 0) 
		{ 
			str[i++] = '0'; 
			str[i] = '\0'; 
			return str; 
		}	  
		// In standard itoa(), negative numbers are handled only with  
		// base 10. Otherwise numbers are considered unsigned. 
		if (num < 0 && base == 10) 
		{ 
			isNegative = true; 
			num = -num; 
		}
		// Process individual digits 
		while (num != 0) 
		{ 
			int rem = num % base; 
			str[i++] = (rem > 9) ? (rem-10) + 'a' : rem + '0'; 
			num = num / base; 
		}
		// If number is negative, append '-' 
		if (isNegative) 
			str[i++] = '-';

		str[i] = '\0'; // Append string terminator
		// Reverse the string 
		reverse(str, i); 
	  
		return str; 
	}

} // namespace base

#endif // !BASE_H
