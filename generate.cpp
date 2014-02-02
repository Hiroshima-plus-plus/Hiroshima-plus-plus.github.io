#include<iostream>
#include<fstream>
#include<tuple>
auto gen_html ( ) -> void
{
	std::ofstream file { "index.html" , std::ios_base::out } ;
	file << u8R"***(<!DOCTYPE html>
<html>
	<head>
		<meta http-equiv="Content-Type" content="text/html;charset=UTF-8" />
		<meta http-equiv="Content-Script-Type" content="text/javascript;charset=UTF-8" />
		<meta http-equiv="Content-Style-Type" content="text/css;charset=UTF-8" />
		<meta name="author" content="広島++" />
		<meta name="description" content="広島++の公式HPです" />
		<meta name="keywords" content="C++,広島,ひろしま,広島++" />
		<title>広島++</title>
		<link rel="stylesheet" href="./css/start.css" type="text/css" />
	</head>
	<body>
		<div style="position:absolute;">
			<div id="start1">広島</div>
			<div id="start2">C++<br /></div>
			<div id="start3">勉強会</div>
		</div>
		<div id="body"><h1>Hello 広島C++勉強会!</h1></div>
	</body>
</html>)***" ;
}
auto gen_css ( ) -> void
{
	std::ofstream file { "css/start.css" , std::ios_base::out } ;
	for ( auto b : { "-webkit-" , "-moz-" , "-o-" , "" } )
	{
		file << '@' << b << u8R"***(keyframes start1
{
	0%
	{
		font-size : 512px ;
		left : 2048px ;
		opacity : 1.0 ;
	}
	5%
	{
		font-size : 512px ;
		left : 0 ;
		opacity : 1.0 ;
	}
	10%
	{
		font-size : 512px ;
		left : -2048px ;
		opacity : 1.0 ;
	}
	15%
	{
		font-size : 384px ;
		left : 1024px ;
		opacity : 1.0 ;
	}
	20%
	{
		font-size : 256px ;
		left : 0 ;
		opacity : 1.0 ;
	}
	60%
	{
		font-size : 256px ;
		left : 0 ;
		opacity : 1.0 ;
	}
	100%
	{
		font-size : 256px ;
		left : 0 ;
		opacity : 0.25 ;
	}
}
)***" ;
	}
	for ( auto b : { "-webkit-" , "-moz-" , "-o-" , "" } )
	{
		file << '@' << b << u8R"***(keyframes start2
{
	0%
	{
		font-size : 512px ;
		left : 2048px ;
		opacity : 1.0 ;
	}
	20%
	{
		font-size : 512px ;
		left : 2048px ;
		opacity : 1.0 ;
	}
	25%
	{
		font-size : 512px ;
		left : 0 ;
		opacity : 1.0 ;
	}
	30%
	{
		font-size : 512px ;
		left : -2048px ;
		opacity : 1.0 ;
	}
	35%
	{
		font-size : 384px ;
		left : 1024px ;
		opacity : 1.0 ;
	}
	40%
	{
		font-size : 256px ;
		left : 0 ;
		opacity : 1.0 ;
	}
	60%
	{
		font-size : 256px ;
		left : 0 ;
		opacity : 1.0 ;
	}
	100%
	{
		font-size : 256px ;
		left : 0 ;
		opacity : 0.25 ;
	}
}
)***" ;
	}
	for ( auto b : { "-webkit-" , "-moz-" , "-o-" , "" } )
	{
		file << '@' << b << u8R"***(keyframes start3
{
	0%
	{
		font-size : 512px ;
		left : 2048px ;
		opacity : 1.0 ;
	}
	40%
	{
		font-size : 512px ;
		left : 2048px ;
		opacity : 1.0 ;
	}
	45%
	{
		font-size : 512px ;
		left : 0 ;
		opacity : 1.0 ;
	}
	50%
	{
		font-size : 512px ;
		left : -2048px ;
		opacity : 1.0 ;
	}
	55%
	{
		font-size : 384px ;
		left : 1024px ;
		opacity : 1.0 ;
	}
	60%
	{
		font-size : 256px ;
		left : 0 ;
		opacity : 1.0 ;
	}
	100%
	{
		font-size : 256px ;
		left : 0 ;
		opacity : 0.25 ;
	}
}
)***" ;
	}
	for ( auto b : { "-webkit-" , "-moz-" , "-o-" , "" } )
	{
		file << '@' << b << u8R"***(keyframes body
{
	0%
	{
		opacity : 0 ;
	}
	60%
	{
		opacity : 0 ;
	}
	100%
	{
		opacity : 1 ;
	}
}
)***" ;
	}
	for ( auto id : { std::make_tuple ( "start1" , "left" ) , std::make_tuple ( "start2" , "left" ) , std::make_tuple ( "start3" , "none" ) } )
	{
		file << '#' << std::get < 0 > ( id ) << u8R"***(
{
	font-size : 256px ;
	position : relative ;
	float : )***" << std::get < 1 > ( id ) << u8R"***( ;
	top : 0 ;
	left : 0 ;
	opacity : 0.25 ;
)***" ;
		for ( auto b : { "-webkit-" , "-moz-" , "-o-" , "" } )
		{
			for ( auto body : { "animation-name : " + std::string { std::get < 0 > ( id ) } , std::string { "animation-duration : 10s" } , std::string { "animation-timing-function : ease-in-out" } } )
			{
				file << '\t' << b << body << " ;" << std::endl ;
			}
		}
		file << "}" << std::endl ;
	}
	file << u8R"***(#body , #body *
{
)***" ;
	for ( auto b : { "-webkit-" , "-moz-" , "-o-" , "" } )
	{
		for ( auto body : { "animation-name : body" , "animation-duration : 10s" , "animation-timing-function : ease-in-out" } )
		{
			file << '\t' << b << body << " ;" << std::endl ;
		}
	}
	file << "}" << std::endl ;
	file << u8R"***(#body
{
	margin-left : auto ;
	margin-right : auto ;
	width : 512px ;
}
)***" ;
}
auto main ( ) -> int
{
	gen_html ( ) ;
	gen_css ( ) ;
}