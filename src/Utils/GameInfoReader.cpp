#include "Utils/GameInfoReader.hpp"
#include "Global.hpp"
#include <boost/filesystem.hpp>
#include <boost/algorithm/string/case_conv.hpp>

GameInfoReader::GameInfoReader(const std::string& file, bool autoload)
	: m_file(file) {
	Log("Constructing GIF");
	Log(file);
	//if (boost::filesystem::exists(boost::filesystem::path(file)))
	//    m_valid = false;
	//else
	m_valid = true;

	if (autoload && m_valid)
		Load();
}

GameInfoReader::~GameInfoReader() {
	//dtor
}

void GameInfoReader::Load() {
	Log("Loading game info");
	Clear();
	// Open a Filestream
	std::ifstream file(m_file);
	char c;
	std::string temp, cat;
	bool ValidLine = false;
	// Let's iterate through the file!
	while (file.good()) {
		file.get(c); // Get the next characters
		if (file.good()) { // Are we good?
			if (c == ':') {
				if (cat.empty()) { // If there is no category on the line
					// Assign the buffer into the catagory.
					cat = temp;
				} else { // We have a category ready
					// Find split point between the future category and data
					int SplitPoint = temp.find_last_of('\n');
					// Extract the new category
					std::string tcat = temp.substr(SplitPoint+1);
					// Extract the data for the current category
					temp = temp.substr(0,SplitPoint);

					// Add the extracted data into the storages
					m_categories.push_back(boost::algorithm::to_lower_copy(cat));
					m_data.push_back(temp);
					Log(cat);
					Log(temp);
					Log("");

					// Set the new category
					cat = tcat;
					Log(to_string(cat.size()));
				}
				// Clear the buffer
				temp.clear();
			} else if (temp.empty() && c == ' ') {}
			else
				temp.push_back(c);

		} else { // End of file or weirdass error
			// Add the extracted data into the storages
			m_categories.push_back(boost::algorithm::to_lower_copy(cat));
			m_data.push_back(temp);
		}
	}
}

void GameInfoReader::Clear() {
	m_categories.clear();
	m_data.clear();
}

const std::string& GameInfoReader::Read(std::string cat) {
	cat = boost::algorithm::to_lower_copy(cat);
	if (!m_valid)
		return std::string("Nope");
	for (unsigned int i = 0; i < m_categories.size(); i++) {
		if (m_categories[i] == cat)
			return m_data[i];
	}
	return std::string(cat).append(":N/A");
}

bool GameInfoReader::SetFile(const std::string& file, bool autoreload) {
	if (boost::filesystem::exists(file))
		m_valid = false;
	else
		m_valid = true;
}
const std::string& GameInfoReader::GetFile() {
	return m_file;
}
