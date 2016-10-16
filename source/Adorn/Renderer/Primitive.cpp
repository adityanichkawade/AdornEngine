#include <Adorn/Renderer/Primitive.h>
#include <GL/glew.h>

namespace Adorn{
    Primitive::Primitive(): 
    _primitiveType(TRIANGLE_STRIP),
    _indexCount(3),
    _startIndex(0){
    }

    Primitive::~Primitive() {
    }
    
    void Primitive::setPrimitiveType(PrimitiveType aPrimitiveType){
        this->_primitiveType = aPrimitiveType;
    }
    
    void Primitive::setStartIndex(int aStartIndex){
        this->_startIndex = aStartIndex;
    }
    
    void Primitive::setIndexCount(int aIndexCount){
        this->_indexCount = aIndexCount;
    }
}
