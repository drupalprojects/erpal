(function ($) {
  menus_by_id = new Array();  //GLOBAL cache for saving a context menu for each id of a node
  $(document).ready(function() {
    var options = Drupal.settings.jstree_options.trees;    
    allowed_parent_child_types = Drupal.settings.jstree_options.allowed_parent_child_types; //definies, which types (type attribute in node) can have which child types, see crrm check_move   
    
    //process several trees
    $.each(options, function(jstree_id, option_arr) { 
      
      //get all variables
      var ajax_url = option_arr.ajax_url;
      var ajax_url_move = option_arr.ajax_url_move;
      var parent_nid = option_arr.parent_nid;      
      //END get variables
      
      $("#"+jstree_id)      
      .bind("before.jstree", function (e, data) {
        $("#alog").append(data.func + "<br />");
      }) 
      
      .bind("dblclick.jstree", function (event) {
         var n = $(event.target).closest("li");         
         // Do my action
         var url = n.attr("uri"); 
         if (typeof url !== "undefined") 
          window.location.href = url;
      })
      
      .jstree({ 
        "crrm" : {
            "move" : {
                "default_position" : "first",
                "check_move" : function (m) { 
                  var parent_type = $('#'+m.r[0].id).attr("type");
                  var child_type = $('#'+m.o[0].id).attr("type");
                  
                  //var allowed_child_types = allowed_parent_child_types
                  //get the type of the node an check if parent child relation is ok if parent child relation is set!
                  var allowed = checkAllowedChild(parent_type, child_type, allowed_parent_child_types);
                  return allowed;
                }
            }
        },
        // List of active plugins    
        "plugins" : [ 
          "themes","json_data","ui","crrm","cookies","dnd","search","hotkeys","contextmenu"
        ],

        // I usually configure the plugin that handles the data first
        // This example uses JSON as it is most common
        "json_data" : { 
          // This tree is ajax enabled - as this is most common, and maybe a bit more complex
          // All the options are almost the same as jQuery's AJAX (read the docs)
          "ajax" : {
            // the URL to fetch the data            
            "url" : function (n) {
              var id = n.attr? n.attr("id").replace("node_","") : parent_nid;                
              return ajax_url+"/"+id;
            },
            // the `data` function is executed in the instance's scope
            // the parameter is the node being loaded 
            // (may be -1, 0, or undefined when loading the root nodes)
            "data" : function (n) { 
              // the result is fed to the AJAX request `data` option					
              var id = n.attr ? n.attr("id").replace("node_","") : parent_nid;
              
              return { 
                "operation" : "get_children", 
              }; 
            },
            "success" : function(data, textStatus, jqXHR) {
              //add the context menu for the node
              $.each(data, function(index, data_obj) {
                
                var context_menu_items = data_obj.context_menu;
                var entity_id = data_obj.attr.entity_id;

                $.each(context_menu_items, function(item_id, item) {
                  var title = item.title;
                  var url = item.url;
                  var key = entity_id;
                  
                  if (typeof menus_by_id[key] === 'undefined')
                    menus_by_id[key] = new Array();  //new array
                  if (typeof menus_by_id[key][item_id] === 'undefined')  
                    menus_by_id[key][item_id] = new Array();  //new array
                  
                  menus_by_id[key][item_id]["title"] = title;
                  menus_by_id[key][item_id]["url"] = url;                  
                });
              });
              
            },
          },
        },
        //configure the Context Menu
        "contextmenu": {
            "items": function(node){
              return customMenu(node, parent_nid);
            }
          },
        // Configuring the search plugin
        "search" : {
          // As this has been a common question - async search
          // Same as above - the `ajax` config option is actually jQuery's AJAX object
          "ajax" : {
            "url" : ajax_url,
            // You get the search string as a parameter
            "data" : function (str) {
              return { 
                "operation" : "search", 
                "search_str" : str 
              }; 
            }
          }
        },
        
        // UI & core - the nodes to initially select and open will be overwritten by the cookie plugin

        // the UI plugin - it handles selecting/deselecting/hovering nodes
        "ui" : {
          // this makes the node with ID node_4 selected onload			
        },
        // the core plugin - not many options here
        "core" : { 
          // just open those two nodes up
          // as this is an AJAX enabled tree, both will be downloaded from the server
          //"initially_open" : [ "node_2" , "node_3" ] 
        }
      })
      .bind("create.jstree", function (e, data) {            
        $.post(
          ajax_url, 
          { 
            "operation" : "create_node", 
            "id" : data.rslt.parent.attr("id").replace("node_",""), 
            "position" : data.rslt.position,
            "title" : data.rslt.name,
            //"type" : data.rslt.obj.attr("rel") //we dont need to use types
          }, 
          function (r) {        
            if(r.status) {
              $(data.rslt.obj).attr("id", "node_" + r.id);
            }
            else {
              $.jstree.rollback(data.rlbk);
            }
          }
        );
      })
      .bind("move_node.jstree", function (e, data) {
        data.rslt.o.each(function (i) {
          var moving_nid = $(this).attr("entity_id");
          $.ajax({
            async : false,
            type: 'POST',
            url: ajax_url_move + "/" + moving_nid,
            data : { 
              "operation" : "move_node", 
              "id" : moving_nid, 
              "new_parent_nid" : data.rslt.cr === -1 ? 1 : data.rslt.np.attr("entity_id"), 
              "position" : data.rslt.cp + i,
              "title" : data.rslt.name,
              "root" : parent_nid,
              "copy" : data.rslt.cy ? 1 : 0
            },
            success : function (r) {                                      
              /*if(!r.status) {
                $.jstree.rollback(data.rlbk);
              }
              else */{
                $(data.rslt.oc).attr("id", "node_" + r.id);
                if(data.rslt.cy && $(data.rslt.oc).children("UL").length) {
                  data.inst.refresh(data.inst._get_parent(data.rslt.oc));
                }
              }
            }
          });
        });
      });  


    });

    
  });
  
  //parent_nid is the top most parent, aka root
  function customMenu(node, parent_nid) {
    // The default set of all items
    
    var entity_id = node.attr("entity_id");

    var type = node.attr("type");
    var rootNode = parent_nid;
    var menu = menus_by_id[entity_id];
    var menu_items = {};
    
    for (key in menu) {
      var item_key = key;
      var item = menu[key];
      var url = item["url"];
      var title = item["title"];
      console.log(title+'--'+url);
      menu_items[item_key] = customMenuNode(title, url);
    }
    
    return menu_items;
  }
  
  function customMenuNode(title, url) {
    var menu_object = {          
      label: title,
      action: function (clicked_node) {          
        var link = url;
        window.location.href = link;
      }      
    }
      
    return menu_object;
  }
  
  /**
  * Checks if the child is allowed to be a child of parent
  */
  function checkAllowedChild(parent_type, child_type, allowed) {
    if (!allowed)
      return true; //if no parent child specification is given, allways allow
    
    allowed_children = allowed[parent_type];
    var is_allowed = false;
    $.each(allowed_children, function (key, value) {
      console.log(value+'--'+child_type);
      if (value+"" == child_type+"")
        is_allowed = true
    });
    
    return is_allowed;
  }
})(jQuery);

