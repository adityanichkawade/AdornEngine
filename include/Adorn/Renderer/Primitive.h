#ifndef PRIMITIVE_H
#define PRIMITIVE_H

namespace Adorn{
    enum PrimitiveType {
        TRIANGLE_STRIP,
        TRIANGLE_FAN
    };
    
    class Primitive {
    public:
        virtual ~Primitive();
        
        void setPrimitiveType(PrimitiveType aPrimitiveType);
        void setIndexCount(int aIndexCount);
        void setStartIndex(int aStartIndex);
		
		virtual void render() = 0;
    protected:
		Primitive();
        PrimitiveType _primitiveType;
        int _startIndex;
        int _indexCount;
    };
}

#endif /* PRIMITIVE_H */

