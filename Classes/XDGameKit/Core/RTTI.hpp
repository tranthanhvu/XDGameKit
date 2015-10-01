//
//  RTTI.hpp
//  GiatXeng
//
//  Created by VuTT5 on 9/23/15.
//
//

#ifndef RTTI_hpp
#define RTTI_hpp

/// Run-time type information
class RTTI: public cocos2d::Ref {
    
public:
    RTTI(const char* name, const RTTI*baseRTTI);
    
    const char*     GetName() const { return m_Name; }
    const RTTI*     GetBaseRTTI() const { return m_BaseRTTI; }
    
protected:
    const char*     m_Name;
    const RTTI*     m_BaseRTTI;
};

/* root class macro declare */
#define DECLARE_RTTI_ROOT(class_name) \
    public: \
    \
    static	const RTTI	sRTTI; \
    \
    static	bool			IsExactKindOf	( const RTTI* rtti, const class_name* object ) \
    { \
        return object == 0 ? false : object->IsExactKindOf(rtti); \
    } \
    \
    static	bool			IsKindOf	( const RTTI* rtti, const class_name* object ) \
    { \
        return object == 0 ? false : object->IsKindOf(rtti); \
    } \
    \
    static	class_name*		DynamicCast	( const RTTI* rtti, const class_name* object ) \
    { \
        return object == 0 ? 0 : object->DynamicCast(rtti); \
    } \
    \
    bool					IsExactKindOf	( const RTTI* rtti ) const \
    { \
        return GetRTTI() == rtti; \
    } \
    \
    bool					IsKindOf	( const RTTI* rtti ) const \
    { \
        const RTTI* temp = GetRTTI(); \
        while (temp) \
        { \
            if (temp == rtti) \
                return true; \
            \
            temp = temp->GetBaseRTTI(); \
        } \
        return false; \
    } \
    \
    class_name*				DynamicCast	( const RTTI* rtti ) const \
    { \
        return IsKindOf(rtti) ? (class_name*) this : 0; \
    } \
    \
    virtual	const RTTI*	GetRTTI		() const { return &sRTTI; }


    /* RTTI class macro declare */
    #define DECLARE_RTTI \
    public: \
        static	const RTTI	sRTTI; \
        virtual const RTTI*	GetRTTI		() const { return &sRTTI; }

    /* Root class macro implement */
    #define IMPLEMENT_RTTI_ROOT(class_name) const RTTI class_name::sRTTI(#class_name, 0)
    /* RTTI class macro implement */
    #define IMPLEMENT_RTTI(class_name, base_name) const RTTI class_name::sRTTI(#class_name, &base_name::sRTTI)

    /* RTTI class macro function */
    #define IS_EXACT_KIND_OF(class_name, object)	class_name::IsExactKindOf(&class_name::sRTTI, object)
    #define IS_KIND_OF(class_name, object)			class_name::IsKindOf(&class_name::sRTTI, object)
    #define DYNAMIC_CAST(class_name, object)		((class_name*)class_name::DynamicCast(&class_name::sRTTI, object))
    #define IS_SAME_CLASS(class_name1, class_name2) (&(class_name1::sRTTI) == &(class_name2::sRTTI))

#endif /* RTTI_hpp */
