(function ($) {
  $(document).ready(function() {
    var options = Drupal.settings.jstree_options;    
    
    //process several trees
    $.each(options, function(jstree_id, option_arr) { 
      
      //get all variables
      var ajax_url = option_arr.ajax_url;
      var parent_nid = option_arr.parent_nid;
      
      //END get variables
      
      $("#"+jstree_id)      
      .bind("before.jstree", function (e, data) {
        $("#alog").append(data.func + "<br />");
      }) 
      
      .jstree({ 
        "crrm" : { 
          "move" : {
            "check_move" : function (m) { 
              var p = this._get_parent(m.o);
              if(!p) return false;
              p = p == -1 ? this.get_container() : p;
              if(p === m.np) return true;
              if(p[0] && m.np[0] && p[0] === m.np[0]) return true;
              return false;
            }
          }
        },
        "dnd" : {
          "drop_target" : false,
          "drag_target" : false
        },
        // List of active plugins    
        "plugins" : [ 
          "themes","json_data","ui","crrm","cookies","dnd","search","types","hotkeys","contextmenu"
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
            }
          }
        },
        //configure the Context Menu
        "contextmenu": {
            "items": function(node){
              return customMenu(node);
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
        // Using types - most of the time this is an overkill
        // read the docs carefully to decide whether you need types
        "types" : {
          // I set both options to -2, as I do not need depth and children count checking
          // Those two checks may slow jstree a lot, so use only when needed
          //"max_depth" : -2,
          //"max_children" : -2,
          // I want only `drive` nodes to be root nodes 
          // This will prevent moving or creating any other type as a root node
          "valid_children" : [ "anforderungok", "anforderungnotok" ],
          "types" : {
            // The default type
            /*"default" : {
              // I want this type to have no children (so only leaf nodes)
              // In my case - those are files
              "valid_children" : "none",
              // If we specify an icon for the default type it WILL OVERRIDE the theme icons
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/file.png"
              }
            },*/
            // The `folder` type
            /*"folder" : {
              // can have files and other folders inside of it, but NOT `drive` nodes
              "valid_children" : [ "default", "folder" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/folder.png"
              }
            },*/
            
            //CUSTOM FOR ANFORDERUNG UND LEISTUNG
            "anforderungok" : {

              "valid_children" : [ "leistungok", "leistungnotok" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/anforderungok.gif"
              }
            },
            "anforderungnotok" : {
              "valid_children" : [ "leistungok", "leistungnotok" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/anforderungnotok.gif"
              }
            },
            "leistungok" : {
              "valid_children" : [ "task-buggy", "task-tested", "task-inserted", "task-in-progress", "task-on-hold", "task-completed" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/leistungok.gif"
              }
            },
            "leistungnotok" : {
              "valid_children" : [ "task-buggy", "task-tested", "task-inserted", "task-in-progress", "task-on-hold", "task-completed" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/leistungnotok.gif"
              }
            },        
            
            //END CUTSOM TYPES
            
            //CUSTOM TYPES FOR STATE!
            "task-buggy" : {
              "valid_children" : [ "task-buggy", "task-tested", "task-inserted", "task-in-progress", "task-on-hold", "task-completed" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/task-buggy.png"
              }
            },
            "task-tested" : {
              "valid_children" : [ "task-buggy", "task-tested", "task-inserted", "task-in-progress", "task-on-hold", "task-completed" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/task-tested.gif"
              }
            },
            "task-inserted" : {
              "valid_children" : [ "task-buggy", "task-tested", "task-inserted", "task-in-progress", "task-on-hold", "task-completed" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/task-inserted.png"
              }
            },
            "task-in-progress" : {
              "valid_children" : [ "task-buggy", "task-tested", "task-inserted", "task-in-progress", "task-on-hold", "task-completed" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/task-in-progress.png"
              }
            },
            "task-on-hold" : {
              "valid_children" : [ "task-buggy", "task-tested", "task-inserted", "task-in-progress", "task-on-hold", "task-completed" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/task-on-hold.png"
              }
            },
            "task-completed" : {
              "valid_children" : [ "task-buggy", "task-tested", "task-inserted", "task-in-progress", "task-on-hold", "task-completed" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/task-completed.png"
              }
            },
            //END CUSTOM TYPES FOR STATE!
            
            // The `drive` nodes 
            "drive" : {
              // can have files and folders inside, but NOT other `drive` nodes
              "valid_children" : [ "default", "folder" ],
              "icon" : {
                "image" : "/sites/all/modules/bsintranet/bsrequirements/img/root.png"
              },
              // those prevent the functions with the same name to be used on `drive` nodes
              // internally the `before` event is used
              "start_drag" : false,
              "move_node" : false,
              "delete_node" : false,
              "remove" : false
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
            "type" : data.rslt.obj.attr("rel")
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
      .bind("remove.jstree", function (e, data) {
        data.rslt.obj.each(function () {
          $.ajax({
            async : false,
            type: 'POST',
            url: ajax_url,
            data : { 
              "operation" : "remove_node", 
              "id" : this.id.replace("node_","")
            }, 
            success : function (r) {
              if(!r.status) {
                data.inst.refresh();
              }
            }
          });
        });
      })
      .bind("rename.jstree", function (e, data) {
        $.post(
          ajax_url, 
          { 
            "operation" : "rename_node", 
            "id" : data.rslt.obj.attr("id").replace("node_",""),
            "title" : data.rslt.new_name
          }, 
          function (r) {
            if(!r.status) {
              $.jstree.rollback(data.rlbk);
            }
          }
        );
      })
      .bind("move_node.jstree", function (e, data) {
        data.rslt.o.each(function (i) {
          $.ajax({
            async : false,
            type: 'POST',
            url: ajax_url,
            data : { 
              "operation" : "move_node", 
              "id" : $(this).attr("id").replace("node_",""), 
              "ref" : data.rslt.cr === -1 ? 1 : data.rslt.np.attr("id").replace("node_",""), 
              "position" : data.rslt.cp + i,
              "title" : data.rslt.name,
              "copy" : data.rslt.cy ? 1 : 0
            },
            success : function (r) {          
              console.log(r);
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
})(jQuery);