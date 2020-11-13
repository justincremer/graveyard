using System;
using System.Collections.Generic;
using System.Linq;
using Commander.Models;
using Microsoft.AspNetCore.JsonPatch;

namespace Commander.Data
{
    public class SqlCommanderRepo : ICommanderRepo
    {
        private readonly CommanderContext _context;

        public SqlCommanderRepo(CommanderContext context)
        {
            _context = context;
        }
        
        public bool SaveChanges() => _context.SaveChanges() >= 0;

        public IEnumerable<Command> GetAllCommands() => _context.Commands.ToList();

        public Command GetCommandById(int id) => _context.Commands.FirstOrDefault(p => p.Id == id);

        public void PostCommand(Command c)
        {
            if(c == null)
                throw new ArgumentNullException(nameof(c));
            
            _context.Commands.Add(c);
            SaveChanges();
        }

        public void PutCommand(Command c) {}

        public void PatchCommand(Command c) {}

        public void DeleteCommand(Command c) 
        {
            if(c == null)
                throw new ArgumentNullException(nameof(c));

            _context.Commands.Remove(c);
        }
    }
}