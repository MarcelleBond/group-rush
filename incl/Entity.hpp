/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 09/01/13 by rhohls          #+#    #+#             */
/*   Updated: 2019/06/09 09/01/13 by rhohls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ENTITY_HPP
# define	ENTITY_HPP

#include <string>

class Entity {
	public:
		Entity();
		Entity(Entity const & src);
		~Entity();
		Entity & operator=(Entity const & src);

		char *getSymbol();
		void moveUp();
		void moveDown();

		const int &getXPos();
		const int &getYPos();
		void setXPos(int update_val);
		void setYPos(int update_val);

		
	private:

	protected:
		int m_xpos;
		int m_ypos;


};

#endif
