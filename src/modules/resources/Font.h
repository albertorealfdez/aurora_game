class Font {
   public:
    virtual ~Font() = default;
    virtual int getSize() const = 0;
    virtual void setSize(int newSize) = 0;
};