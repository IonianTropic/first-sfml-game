#ifndef GAME_TILE_MAP_H_
#define GAME_TILE_MAP_H_

#include <SFML/Graphics.hpp>

namespace game {
class TileMap: public sf::Drawable, public sf::Transformable {
    public:
        bool load(
            const std::string& tileset,
            sf::Vector2u tileSize,
            const int* tiles,
            unsigned int width,
            unsigned int height
        );
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
            // apply the transform
            states.transform *= getTransform();

            // apply the tileset texture
            states.texture = &_tileset;

            // draw the vertex array
            target.draw(_vertices, states);
        }
        sf::VertexArray _vertices;
        sf::Texture _tileset;
};
} // namespace game

#endif // GAME_TILE_MAP_H_