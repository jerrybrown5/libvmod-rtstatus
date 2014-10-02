#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

#include "vrt.h"
#include "vrt_obj.h"
#include "cache/cache.h"
#include "vmod_rtstatus.h"
 char *html = "<title>Varnish Status</title><link rel=\"stylesheet\" href=\"http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css\"><link rel=\"stylesheet\" href=\"http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap-theme.min.css\"><script src=\"http://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js\"></script><script src=\"http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js\"></script><script type=\"text/javascript\" src=\"http://code.jquery.com/jquery-1.4.2.min.js\"></script><style type=\"text/css\">.info { white-space: pre;}.backend { white-space: pre;}.be { white-space: pre;}.spoilbe { white-space: pre;}.col-xs-12 {padding-top: 5%;}</style></head><body><header><h1><b>VARNISH STATUS</b></h1></header><div class=\"container\" style=\"float:left;text-align:left;\"><div class=\"info\" ><script type=\"text/javascript\">var myVar = setInterval(function(){info()}, 1000);function info(){$.getJSON( \"/rtstatus.json\", function( data ) {var items = [];var index = 0;	items.push(\"<p>\"+ \"<b>Varnish version: </b> \" + data.varnish_version + \",\" + \"</p>\");items.push(\"<p>\"+ \"<b>Server identity: </b> \" + data.server_id + \",\" + \"</p>\");	items.push(\"<p>\"+ \"<b>Client identity: </b> \" + data.client_id + \",\" + \"</p>\");	items.push(\"<p>\"+ \"<b>Varnish Uptime: </b> \" + data.uptime + \" s\" + \"</p>\");items.push(\"<p>\"+ \"<b>Hitrate: </b>\"+ \" \" + data.hitrate + \" %\"+ \"</p>\");	items.push(\"<p>\"+ \"<b>Load: </b>\"+ \" \" + data.load + \" req/s\"+ \"</p>\");	$(\"div.info\").html(\"\");	$( \"<p/>\", {\"class\": \"my-new-list\",html: items.join( \"\" )}).appendTo( \"div.info\" );})();};info();</script></div><h1>Backends overview</h1><div class=\"be\"><script type=\"text/javascript\">$.getJSON( \"/rtstatus.json\", function( data ) {var items = [];var cont = 0;	var i = 1;$.each( data, function( key, val ) {	if( val.type === \"MAIN\" && key.contains('backend')){items.push( \"<p>\" + \"<b>\" + val.descr + \"</b>\"  +\" :  \"+  val.value + \"</p>\" );}};$(\"div.be\").html(\"\")$( \"<p/>\", {\"class\": \"my-new-list\",html: items.join( \"\" )}).appendTo( \"div.be\" );	})();  </script></div> <h1>Backends</h1>    <div class=\"backend\">      <script type=\"text/javascript\">	var myVar = setInterval(function(){backend()}, 1000);	function backend(){	$.getJSON( \"/rtstatus.json\", function( data ) {	var items = [];	var i,j;	var cont;	$.each( data,function( key, val ) {	if(key === \"backend\"){	var tmp = data.backend;	}	if(tmp) {	for(i = 0, cont = 0; i < tmp.length;i++){	items.push( \"<p>\" + \"<b>Name: </b> \" + tmp[i].name + \" : \" + tmp[i].value + \",\" + \"</p>\" );	}}});	$(\"div.backend\").html(\"\")	$( \"<p/>\", {	\"class\": \"my-new-list\",	html: items.join( \"\" )	}).appendTo( \"div.backend\" );	})();	};	backend();      </script>     </div>    <script>      function openSpoiler(id){      var a = document.getElementById(id).style;      a.display = a.display=='block'?'none':'block'}    </script>    <BR>    <a href=\"javascript:openSpoiler('spoilbe')\">      <b>Show details backends</b></a>    <div id=\"spoilbe\" class=\"row\" style=\"display: none;\">      <div class=\"col-xs-5\">	<h2>Details:</h2>	<p4>details</p4>	<script type=\"text/javascript\">	  $.getJSON( \"/rtstatus.json\", function( data ) {	  var items = [];	  var cont = 0;	  var i = 1;	  $.each( data, function( key, val ) {	  if( val.type === \"VBE\"){	  if(cont % 11 === 0){	  items.push(\"BACKEND :  \" + \"<b>\" + val.ident + \"</b><BR>\" );	  }	  items.push( \"<span>\" + val.descr + \" : \" + val.value  + \"</span><BR>\" );	  cont++;	  } 	  });	  $(\"p4\").html(\"\")	  $( \"<ul/>\", {	  \"class\": \"my-new-list\",	  html: items.join( \"\" )	  }).appendTo( \"p4\" );	  })();	</script>      </div>  </div><BR>    <script>      function openSpoiler(id){      var a = document.getElementById(id).style;      a.display = a.display=='block'?'none':'block'}    </script>    <a href=\"javascript:openSpoiler('spoil')\">      <b>Show detailed counters</b></a>    <div id=\"spoil\" class=\"row\" style=\"display: none;\">      <div class=\"col-xs-5\">	<h2>Description:</h2>	<p1>short description</p1>	<script type=\"text/javascript\">	  $.getJSON( \"/rtstatus.json\", function( data ) {	  var items = [];	  var cont = 0;	  var i = 1;	  $.each( data, function( key, val ) {	  if(cont>7){	  items.push( \"<span>\" + \"<sub>\"+ i + \". \" + \"</sub>\" + \"[\" + val.descr + \"]\" + \"</span><BR>\" );	  i++;	  }	  cont++;	  });	  $(\"p1\").html(\"\")	  $( \"<ul/>\", {	  \"class\": \"my-new-list\",	  html: items.join( \"\" )	  }).appendTo( \"p1\" );	  })();      </script>    </div>    <div class=\"col-xs-5\">      <h2>Name:</h2>      <p2>name</p2>      <script type=\"text/javascript\" style=\"float:left\">	$.getJSON( \"/rtstatus.json\", function( data ) {	var items = [];	var cont = 0;	var i = 1;	$.each( data, function( key, val ) {	if(cont>7){	items.push( \"<span>\" + \"<sub>\"+ i + \". \" + \"</sub>\" + \"[\" + key + \"]\" + \"</span><BR>\" );	i++;	}cont++;	});	$(\"p2\").html(\"\")	$( \"<ul/>\", {	\"class\": \"my-new-list\",	html: items.join( \"\" )	}).appendTo( \"p2\" );	})();      </script>    </div>    <div class=\"col-xs-2\">      <h2>Value:</h2>      <p3>value</p3>      <script type=\"text/javascript\">	var myVar = setInterval(function(){value()}, 1000);	function value(){	$.getJSON( \"/rtstatus.json\", function( data ) {	var items = [];	var cont = 0;	var i = 1;	$.each( data, function( key, val ) {	if(cont>7){	items.push( \"<span>\" + \"<sub>\"+ i + \". \" + \"</sub>\" + val.value + \"</span><BR>\");	i++;	}	cont++;	});	$(\"p3\").html(\"\")	$( \"<ul/>\", {	\"class\": \"my-new-list\",	html: items.join( \"\" )	}).appendTo( \"p3\" );	})();	};value();      </script>    </div>  </div></div><hr><div class=\"row\">  <div class=\"col-xs-12\">    <footer>      <a href=\"/rtstatus.json\" target=\"_blank\">Complete JSON file</a><br/>      <a href=\"https://github.com/arianna-aondio/libvmod-rtstatus\" target=\"_blank\">Github repository</a><br /><br /><br />      <p>&copy;Copyright 2014 Varnish Software AS</p>    </footer>  </div></div></div></body></html>" ;





VCL_STRING
vmod_html(const struct vrt_ctx *ctx)
{
    char *p;
    unsigned u, v;
  
    int i;
    char tmp[128];
    WS_Reserve(ctx->ws, 0); /* Reserve some work space */
    p = ctx->ws->f;	/* Front of workspace area */
   
    
   //for( i=0 ; i< strlen(html); i++){
	
	STRCAT(p, html, ctx);
  // }
    /* Update work space with what we've used */
    WS_Release(ctx->ws, v);
    return (p);
    

}

