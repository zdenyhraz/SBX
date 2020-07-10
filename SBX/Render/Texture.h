#pragma once
#include "Stdafx.h"

// <TEXTURES>
// - loads image from disk
// - texture slot - int - max 32, we can reuse them, whatever
// - set texture slot in bind, uniform needs to match
// - texture coordinates in vertex array - in [0, 1] based on x/y
class Texture
{
public:
	Texture( const std::string &path );
	~Texture();

	void Bind( unsigned int slot = 0 ) const;
	void Unbind() const;

	inline int GetWidth() const { return m_Width; }
	inline int GetHeight() const { return m_Height; }

private:
	unsigned int m_RendererId;
	std::string m_Filepath;
	unsigned char *m_LocalBuffer;
	int m_Width;
	int m_Height;
	int m_BPP;
};