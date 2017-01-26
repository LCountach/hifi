//
//  Created by Bradley Austin Davis on 2017/01/25
//  Copyright 2013-2017 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//
#include "TextureTable.h"
#include "Texture.h"

using namespace gpu;

TextureTable::TextureTable() { }

TextureTable::TextureTable(const std::initializer_list<TexturePointer>& textures) {
    auto max = std::min(COUNT, textures.size());
    auto itr = textures.begin();
    size_t index = 0;
    while (itr != textures.end() && index < max) {
        setTexture(index, *itr);
        ++index;
    }
}

TextureTable::TextureTable(const std::array<TexturePointer, COUNT>& textures) : _stamp(1), _textures(textures) {
}

void TextureTable::setTexture(size_t index, const TexturePointer& texturePointer) {
    if (index >= COUNT || _textures[index] == texturePointer) {
        return;
    }
    ++_stamp;
    _textures[index] = texturePointer;
}

void TextureTable::setTexture(size_t index, const TextureView& textureView) {
    setTexture(index, textureView._texture);
}
