#ifndef GAMEINFOREADER_H
#define GAMEINFOREADER_H

#include <string>
#include <vector>

class GameInfoReader {
public:
	/** Default constructor */
	GameInfoReader(const std::string& file, bool autoload = true);
	/** Default destructor */
	virtual ~GameInfoReader();

	void Load();
	void Clear();
	bool IsValid();
	const std::string& Read(std::string cat);
	bool SetFile(const std::string& file, bool autoreload = true);
	const std::string& GetFile();
protected:
private:
	bool m_valid;
	std::string m_file;
	std::vector<std::string> m_categories;
	std::vector<std::string> m_data;
};

#endif // GAMEINFOREADER_H
