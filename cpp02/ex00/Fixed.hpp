class Fixed
{
	
	private:
	int fixedPointNumberValue;
	static const int fractionalBits = 8;
	public:
	~Fixed();
	Fixed();
	Fixed(const Fixed &obj);
	Fixed& operator=(const Fixed& obj);
	int getRawBits() const;
	void setRawBits(int raw);
};