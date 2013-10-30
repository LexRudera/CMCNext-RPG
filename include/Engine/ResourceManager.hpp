// The Universal Resource Manager
//------------------------------------------------------------------
// The place you keep and manage all the resources. Be it textures,
// fonts, sounds, it's here. Should be, at least.

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

namespace lpe{
enum Persistence
{ Level, Campaign, Global, };

class ResourceManager {
	class FontEntry;
	class TextureEntry;
	class SoundEntry;

public:
	// Global stuph
	ResourceManager();
	virtual ~ResourceManager();

	void Clear(Persistence depth = Level);

	// Fonts
	const sf::Font* LoadFont(const sf::String& Name, const sf::String& FileName, const Persistence& persistence = Level);
	bool UnloadFont(const sf::String& strng);
	const sf::Font* GetFont(const sf::String& strng);

	// Textures
	const sf::Texture* LoadTexture(const sf::String& Name, const sf::String& FileName, const Persistence& persistence = Level);
	bool UnloadTexture(const sf::String& strng);
	const sf::Texture* GetTexture(const sf::String& strng);
	const sf::Texture* GetFallbackTexture() {
		return FallbackTexture;
	}

	// Sounds
	const sf::SoundBuffer* LoadSound(const sf::String& Name, const sf::String& FileName, const Persistence& persistence = Level);
	bool UnloadSound(const sf::String& strng);
	const sf::SoundBuffer* GetSound(const sf::String& strng);

protected:
private:
	// Fonts
	sf::String FontDirectory;
	std::vector<FontEntry*> m_Fonts;

	// Textures
	sf::String TextureDirectory;
	std::vector<TextureEntry*> m_Textures;
	sf::Texture* FallbackTexture;

	// Sounds
	sf::String SoundDirectory;
	std::vector<SoundEntry*> m_Sounds;

	class ResourceEntry {
	public:
		ResourceEntry(const sf::String& Name, const sf::String& FileName, const Persistence& persist) : m_FileName(FileName), m_Name(Name), m_Persistance(persist) {}
		virtual ~ResourceEntry() {}
		const sf::String& getName() const {
			return m_Name;
		}
		void setName(const sf::String& name) {
			m_Name = name;
		}
		const sf::String& getFilename() const {
			return m_FileName;
		}
		const Persistence& getPersistance() const {
			return m_Persistance;
		}
		void setPersistance(const Persistence& persist) {
			m_Persistance = persist;
		}
	private:
		sf::String m_FileName;
		sf::String m_Name;
		Persistence m_Persistance;
	};

	class FontEntry : public ResourceEntry, public sf::Font {
	public:
		FontEntry(const sf::String& Name, const sf::String& FileName, const Persistence& persist) : ResourceEntry(Name, FileName, persist) {}
		virtual ~FontEntry() {}
	};

	class TextureEntry : public ResourceEntry, public sf::Texture {
	public:
		TextureEntry(const sf::String& Name, const sf::String& FileName, const Persistence& persist) : ResourceEntry(Name, FileName, persist) {}
		virtual ~TextureEntry() {}
	};

	class SoundEntry : public ResourceEntry, public sf::SoundBuffer {
	public:
		SoundEntry(const sf::String& Name, const sf::String& FileName, const Persistence& persist) : ResourceEntry(Name, FileName, persist) {}
		virtual ~SoundEntry() {}
	};
};
}
#endif // RESOURCEMANAGER_H
