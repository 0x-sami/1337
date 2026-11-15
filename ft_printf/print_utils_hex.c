#include "ft_printf.h"

static int ft_putptr_rec(uintptr_t address);

int	ft_puthex(unsigned long n, char flag)
{
	char	*lower_hex;
	char	*upper_hex;
	int		count;

	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	count = 0;
	if (flag == 'x')
	{
		if (n / 16)
			count += ft_puthex(n / 16, flag);
		count += ft_putchar(lower_hex[n % 16]);
	}
	else if (flag == 'X')
	{
		if (n / 16)
			count += ft_puthex(n / 16, flag);
		count += ft_putchar(upper_hex[n % 16]);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	uintptr_t	address;
	int			count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
    count = 0;
	address = (uintptr_t)ptr;
	count += write(1, "0x", 2);
	count += ft_putptr_rec(address);
	return (count);

}

static int ft_putptr_rec(uintptr_t address)
{
	char *hex;
	int	count;

	hex = "0123456789abcdef";
	count = 0;
	if (address >= 16)
		count += ft_putptr_rec(address / 16);
	count += write(1, &hex[address % 16], 1);
	return (count);
}