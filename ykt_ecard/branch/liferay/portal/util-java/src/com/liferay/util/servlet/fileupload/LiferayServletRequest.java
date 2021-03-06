/**
 * Copyright (c) 2000-2008 Liferay, Inc. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

package com.liferay.util.servlet.fileupload;

import java.io.IOException;

import javax.servlet.ServletInputStream;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletRequestWrapper;

/**
 * <a href="LiferayServletRequest.java.html"><b><i>View Source</i></b></a>
 *
 * @author Brian Myunghun Kim
 * @author Brian Wing Shun Chan
 *
 */
public class LiferayServletRequest extends HttpServletRequestWrapper {

	public LiferayServletRequest(HttpServletRequest req) {
		super(req);

		_req = req;
	}

	public ServletInputStream getInputStream() throws IOException {
		if (_lis == null) {
			_lis = new LiferayInputStream(_req);

			return _lis;
		}
		else {

			// Return the cached input stream the second time the user requests
			// the input stream, otherwise, it will return an empty input stream
			// because it has already been parsed

			return _lis.getCachedInputStream();
		}
	}

	private HttpServletRequest _req;
	private LiferayInputStream _lis = null;

}