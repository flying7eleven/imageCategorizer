#if !defined( __VERSIONINFORMATION_HXX__ )
#define __VERSIONINFORMATION_HXX__

// the required include files
#include <string>

	unsigned short int getVersionMajor();
	unsigned short int getVersionMinor();
	unsigned short int getVersionPatch();
	const std::string getVersionSHA1();
	const std::string getVersionString();

#endif /* if !defined( __VERSIONINFORMATION_HXX__ ) */
