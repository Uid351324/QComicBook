/*
 * This file is a part of QComicBook.
 *
 * Copyright (C) 2005-2010 Pawel Stolowski <stolowski@gmail.com>
 *
 * QComicBook is free software; you can redestribute it and/or modify it
 * under terms of GNU General Public License by Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY. See GPL for more details.
 */

#ifndef __FRAME_CACHE_H
#define __FRAME_CACHE_H

#include <QObject>
#include <QMap>
#include <ComicFrameList.h>

namespace QComicBook
{
	class FrameCache: public QObject
	{
		Q_OBJECT

		public:
			static FrameCache& instance();

		public slots:
			void insert(const ComicFrameList &frames);
			bool has(int page) const;
			ComicFrameList get(int page) const;
			void clear();
		
		private:
			FrameCache();
			FrameCache(const FrameCache &);
			~FrameCache();

			QMap<int, ComicFrameList> m_frames;
	};
}

#endif
