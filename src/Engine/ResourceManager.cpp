#include "Utilities.hpp"
#include "ResourceManager.hpp"

namespace lpe{
ResourceManager::ResourceManager() {
	FontDirectory = "fonts\\";
	TextureDirectory = "textures\\";
	SoundDirectory = "sounds\\";
	FallbackTexture = new sf::Texture();
	FallbackTexture->create(50, 50);
}

ResourceManager::~ResourceManager() {
	delete FallbackTexture;
}

void ResourceManager::Clear(Persistence depth) {
	if (depth == Level)
		Log("Clearing Level resources");
	else if (depth == Campaign)
		Log("Clearing Campaign resources");
	else
		Log("Clearing Global resources");

	// Fonts
	std::vector<FontEntry*>::iterator fit = m_Fonts.begin();
	for(unsigned int i = 0; i<m_Fonts.size(); i++) {
		if (m_Fonts[i]->getPersistance() <= depth) {
			Log("Clearing Resource, Font: " + m_Fonts[i]->getName() + ", " + m_Fonts[i]->getFilename());
			delete m_Fonts[i];
			m_Fonts.erase(fit);
		}
		fit++;
	}

	// Textures
	std::vector<TextureEntry*>::iterator tit = m_Textures.begin();
	for(unsigned int i = 0; i<m_Textures.size(); i++) {
		if (m_Textures[i]->getPersistance() <= depth) {
			Log("Clearing Resource, Texture: " + m_Textures[i]->getName() + ", " + m_Textures[i]->getFilename());
			delete m_Textures[i];
			m_Textures.erase(tit);
		}
		tit++;
	}

	// Sounds
	std::vector<SoundEntry*>::iterator sit = m_Sounds.begin();
	for(unsigned int i = 0; i<m_Sounds.size(); i++) {
		if (m_Sounds[i]->getPersistance() <= depth) {
			Log("Clearing Resource, Sound: " + m_Sounds[i]->getName() + ", " + m_Sounds[i]->getFilename());
			delete m_Sounds[i];
			m_Sounds.erase(sit);
		}
		sit++;
	}
}

// ---Fonts---
const sf::Font* ResourceManager::LoadFont(const sf::String& Name, const sf::String& FileName, const Persistence& persist) {
	Log("Loading Resource, Font: " + Name + ", " + FileName);
	// Check for existing font
	FontEntry* e = 0;
	if (persist != Level) {
		for(unsigned int i = 0; i<m_Fonts.size(); i++) {
			if(m_Fonts[i]->getFilename() == FileName ) {
				e = m_Fonts[i];
				break;
			}
		}
	}
	// In case the object doesn't exist, or it is only gonna be kept
	// through the single level. Then there's no concer that the resource
	// might already be in loaded across scenes.
	if (e == 0) {
		FontEntry* t = new FontEntry(Name, FileName, persist);
		if(!t->loadFromFile(FontDirectory + FileName)) {
			delete t;
			return 0;
		}
		m_Fonts.push_back(t);
		return t;
	} else {
		// Else just change the name acordingly and return it. Nothing added.
		e->setName(Name);
		return e;
	}
}

bool ResourceManager::UnloadFont(const sf::String& strng) {
	FontEntry* tf = 0;
	std::vector<FontEntry*>::iterator it = m_Fonts.begin();
	for(unsigned int i = 0; i<m_Fonts.size(); i++) {
		if(m_Fonts[i]->getName() == strng ||m_Fonts[i]->getFilename() == strng ) {
			tf = m_Fonts[i];
			break;
		}
		it++;
	}
	if(tf == 0)
		return false;
	delete tf;
	m_Fonts.erase(it);
	return true;
}

const sf::Font* ResourceManager::GetFont(const sf::String& strng) {
	for(unsigned int i = 0; i<m_Fonts.size(); i++) {
		if(m_Fonts[i]->getName() == strng ||m_Fonts[i]->getFilename() == strng ) {
			return m_Fonts[i];
		}
	}
	return 0;
}

// ---Textures---
const sf::Texture* ResourceManager::LoadTexture(const sf::String& Name, const sf::String& FileName, const Persistence& persist) {
	/*TextureEntry* t = new TextureEntry(Name, FileName, persist);
	if(!t->loadFromFile(TextureDirectory + FileName))
	{
	    delete t;
	    return 0;
	}
	m_Textures.push_back(t);
	return t;*/
	Log("Loading Resource, Texture: " + Name + ", " + FileName);
	// Check for existing Texture
	TextureEntry* e = 0;
	if (persist != Level) {
		for(unsigned int i = 0; i<m_Textures.size(); i++) {
			if(m_Textures[i]->getFilename() == FileName ) {
				e = m_Textures[i];
				break;
			}
		}
	}
	// In case the object doesn't exist, or it is only gonna be kept
	// through the single level. Then there's no concer that the resource
	// might already be in loaded across scenes.
	if (e == 0) {
		TextureEntry* t = new TextureEntry(Name, FileName, persist);
		if(!t->loadFromFile(TextureDirectory + FileName)) {
			delete t;
			return 0;
		}
		m_Textures.push_back(t);
		return t;
	} else {
		// Else just change the name acordingly and return it. Nothing added.
		e->setName(Name);
		return e;
	}
}

bool ResourceManager::UnloadTexture(const sf::String& strng) {
	TextureEntry* tf = 0;
	std::vector<TextureEntry*>::iterator it = m_Textures.begin();
	for(unsigned int i = 0; i<m_Textures.size(); i++) {
		if(m_Textures[i]->getName() == strng ||m_Textures[i]->getFilename() == strng ) {
			tf = m_Textures[i];
			break;
		}
		it++;
	}
	if(tf == 0)
		return false;
	delete tf;
	m_Textures.erase(it);
	return true;
}

const sf::Texture* ResourceManager::GetTexture(const sf::String& strng) {
	for(unsigned int i = 0; i<m_Textures.size(); i++) {
		if(m_Textures[i]->getName() == strng ||m_Textures[i]->getFilename() == strng ) {
			return m_Textures[i];
		}
	}
	return 0;
}

// ---Sounds---
const sf::SoundBuffer* ResourceManager::LoadSound(const sf::String& Name, const sf::String& FileName, const Persistence& persist) {
	/*SoundEntry* t = new SoundEntry(Name, FileName, persist);
	if(!t->loadFromFile(SoundDirectory + FileName))
	{
	    delete t;
	    return 0;
	}
	m_Sounds.push_back(t);
	return t;*/
	Log("Loading Resource, Sound: " + Name + ", " + FileName);
	// Check for existing Sound
	SoundEntry* e = 0;
	if (persist != Level) {
		for(unsigned int i = 0; i<m_Sounds.size(); i++) {
			if(m_Sounds[i]->getFilename() == FileName ) {
				e = m_Sounds[i];
				break;
			}
		}
	}
	// In case the object doesn't exist, or it is only gonna be kept
	// through the single level. Then there's no concer that the resource
	// might already be in loaded across scenes.
	if (e == 0) {
		SoundEntry* t = new SoundEntry(Name, FileName, persist);
		if(!t->loadFromFile(SoundDirectory + FileName)) {
			delete t;
			return 0;
		}
		m_Sounds.push_back(t);
		return t;
	} else {
		// Else just change the name acordingly and return it. Nothing added.
		e->setName(Name);
		return e;
	}
}

bool ResourceManager::UnloadSound(const sf::String& strng) {
	SoundEntry* tf = 0;
	std::vector<SoundEntry*>::iterator it = m_Sounds.begin();
	for(unsigned int i = 0; i<m_Sounds.size(); i++) {
		if(m_Sounds[i]->getName() == strng ||m_Sounds[i]->getFilename() == strng ) {
			tf = m_Sounds[i];
			break;
		}
		it++;
	}
	if(tf == 0)
		return false;
	delete tf;
	m_Sounds.erase(it);
	return true;
}

const sf::SoundBuffer* ResourceManager::GetSound(const sf::String& strng) {
	for(unsigned int i = 0; i<m_Sounds.size(); i++) {
		if(m_Sounds[i]->getName() == strng ||m_Sounds[i]->getFilename() == strng ) {
			return m_Sounds[i];
		}
	}
	return 0;
}
}
