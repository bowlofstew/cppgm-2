
package require Itcl

catch {namespace import ::itcl::*}


class IDBFactory {
    method create { id } {
        createEmployee $id
    }
    method createEmployee { id }
}


class DBFactoryImp1 {
    inherit IDBFactory

    method createEmployee { id } {
        puts "imp1::createEmployee oracle $id"
    }
}

class DBFactoryImp2 {
    inherit IDBFactory 

    method createEmployee { id } {
        puts "imp2::createEmployee file $id"
    }
}

class PayRoll {
    variable db
    constructor { aDb } { 
        set db $aDb 
    }

    destructor {
        delete $db
    }

    method make_emp_record { id } {
        $db create $id
    }
}


set payRoll [PayRoll #auto [DBFactoryImp1 #auto]]
$payRoll make_emp_record "rich"



